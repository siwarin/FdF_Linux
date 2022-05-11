/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:44:20 by siwarin           #+#    #+#             */
/*   Updated: 2018/11/21 18:33:52 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	size_t	i;
	t_list	**a;

	if (!*alst)
		return ;
	a = alst;
	i = ft_strlen((const char *)*alst);
	del(*alst, i);
	*alst = NULL;
}
