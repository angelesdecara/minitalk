/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:28:17 by angrodri          #+#    #+#             */
/*   Updated: 2022/06/22 11:19:49 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen((char *)s);
	i = 0;
	while (*(s + len) != (char)c && len > 0)
		len--;
	if (*(s + len) == (char)c)
		return ((char *)(s + len));
	else
		return (0);
}
