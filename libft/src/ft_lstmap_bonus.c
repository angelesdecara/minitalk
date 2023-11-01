/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:26:01 by angrodri          #+#    #+#             */
/*   Updated: 2022/07/17 11:03:44 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapa;
	t_list	*dummy;
	t_list	*newel;

	if (lst == NULL)
		return (NULL);
	mapa = NULL;
	dummy = lst;
	while (dummy)
	{
		newel = ft_lstnew(f(dummy->content));
		if (!newel)
		{
			ft_lstclear(&mapa, del);
			return (NULL);
		}
		ft_lstadd_back(&mapa, newel);
		dummy = dummy->next;
	}
	return (mapa);
}
