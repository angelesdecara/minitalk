/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:45:22 by angrodri          #+#    #+#             */
/*   Updated: 2022/07/17 10:07:00 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	inc2int1(int *i, int *j)
{
		*i = *i + 1;
		*j = *j + 1;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		tofind;

	i = 0;
	tofind = ft_strlen((char *)needle);
	if (tofind == 0)
		return ((char *)haystack);
	while (*((char *)haystack + i) != '\0' && (size_t)i < len)
	{
		j = 0;
		if (*((char *)haystack + i) == *((char *)needle + j))
		{
			while (*((char *)haystack + i) == *((char *)needle + j) \
					&& (size_t)i < len && j < tofind)
				inc2int1(&i, &j);
			if (j == tofind)
				return (&(*((char *)haystack + i - j)));
			else
				i = i - j;
		}
		i++;
	}
	return (0);
}
