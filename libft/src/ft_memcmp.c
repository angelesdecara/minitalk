/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:32:42 by angrodri          #+#    #+#             */
/*   Updated: 2022/06/20 12:56:51 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	ns1;
	int	ns2;

	ns1 = 0;
	ns2 = 0;
	while (n-- > 0)
	{
		ns1 += *(unsigned char *)s1;
		ns2 += *(unsigned char *)s2;
		if (*(char *)s1 != *(char *)s2)
			return (ns1 - ns2);
		s1++;
		s2++;
	}
	return (ns1 - ns2);
}
