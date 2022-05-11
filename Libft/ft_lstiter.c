/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:39:13 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/22 15:56:45 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*t;
	t_list	*a;

	if (!lst)
		return ;
	a = lst;
	while (a != NULL)
	{
		t = a->next;
		f(a);
		a = t;
	}
}
