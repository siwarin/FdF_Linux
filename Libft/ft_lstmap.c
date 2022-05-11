/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:42:56 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/27 14:42:08 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *a;
	t_list *b;

	if (!lst)
		return (NULL);
	b = f(lst);
	a = b;
	while (lst->next)
	{
		lst = lst->next;
		if (!(b->next = f(lst)))
		{
			free(b->next);
			return (NULL);
		}
		b = b->next;
	}
	return (a);
}
