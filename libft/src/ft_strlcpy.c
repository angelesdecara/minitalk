/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:47:24 by angrodri          #+#    #+#             */
/*   Updated: 2022/06/20 16:39:03 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while ((unsigned long)i < dstsize && *(src + i) != '\0' && dstsize > 0)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if ((unsigned long)i == dstsize)
		i--;
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}
