/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:11:29 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/22 14:54:17 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tab;

	if (!(tab = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tab->content = NULL;
		tab->content_size = 0;
	}
	else
	{
		tab->content_size = content_size;
		if (!(tab->content = malloc(content_size)))
		{
			free(tab);
			return (NULL);
		}
		ft_memcpy(tab->content, content, content_size);
	}
	tab->next = NULL;
	return (tab);
}
