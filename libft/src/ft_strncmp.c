/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:51:28 by angrodri          #+#    #+#             */
/*   Updated: 2022/06/22 14:08:55 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	n1;
	int	n2;

	while (n > 0 && *s1 == *s2)
	{
		n1 = (unsigned char) *s1;
		n2 = (unsigned char) *s2;
		if (!*s1)
			break ;
		n--;
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	n1 = (unsigned char) *s1;
	n2 = (unsigned char) *s2;
	if (n1 > n2)
		return (1);
	if (n1 < n2)
		return (-1);
	else
		return (0);
}
