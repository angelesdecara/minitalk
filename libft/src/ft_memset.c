/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:43:52 by angrodri          #+#    #+#             */
/*   Updated: 2022/06/16 18:52:04 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*bb;

	bb = b;
	i = 0;
	while ((unsigned long)i < len)
	{
		*(bb + i) = c;
		i++;
	}
	return (b);
}
