/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:36:28 by angrodri          #+#    #+#             */
/*   Updated: 2022/06/22 16:07:42 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	dlen;
	int	slen;
	int	j;

	dlen = ft_strlen(dst);
	slen = ft_strlen((char *)src);
	j = 0;
	if (dstsize < (unsigned int)dlen)
		return (dstsize + slen);
	if (dstsize == 0)
		return (slen);
	j = 0;
	while (*(src + j) != '\0' && (size_t)j + 1 < dstsize - dlen)
	{
		*(dst + dlen + j) = *(src + j);
		j++;
	}
	*(dst + dlen + j) = '\0';
	return (dlen + slen);
}
