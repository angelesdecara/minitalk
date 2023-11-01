/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:09:43 by angrodri          #+#    #+#             */
/*   Updated: 2022/07/14 19:20:09 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*mylist;
	t_list	*tmp;

	if (*lst == NULL || !del)
		return ;
	mylist = *lst;
	while (mylist)
	{
		tmp = mylist->next;
		del(mylist->content);
		free(mylist);
		mylist = tmp;
	}
	*lst = NULL;
}
