/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:48:04 by siwarin           #+#    #+#             */
/*   Updated: 2019/01/11 15:44:44 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list			*ft_good_file(t_list **file, int fd)
{
	t_list	*t;

	t = *file;
	while (t)
	{
		if ((int)t->content_size == fd)
			return (t);
		t = t->next;
	}
	t = ft_lstnew("\0", fd);
	ft_lstadd(file, t);
	t = *file;
	return (t);
}

static unsigned int		ft_strline(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static int				ft_check(char *s)
{
	if (ft_strchr(s, '\n'))
	{
		ft_strcpy(s, ft_strchr(s, '\n') + 1);
		return (0);
	}
	if (ft_strline(s) > 0)
	{
		ft_strcpy(s, ft_strchr(s, '\0'));
		return (0);
	}
	return (1);
}

static char				*ft_strjoinre(char *s1, char *s2, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(ft_strlen(s1) + len + 1);
	while (*s1)
		str[i++] = *s1++;
	while (*s2 && len--)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

int						get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*tab;
	int				j;
	char			*tmp;
	t_list			*c;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	c = ft_good_file(&tab, fd);
	while (!(ft_strchr(c->content, '\n')) && (j = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[j] = '\0';
		tmp = c->content;
		c->content = ft_strjoinre(tmp, buf, j);
		free(tmp);
	}
	*line = ft_strsub(c->content, 0, ft_strline(c->content));
	if (ft_check(c->content) == 1)
		return (0);
	return (1);
}
