/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:01:32 by angrodri          #+#    #+#             */
/*   Updated: 2022/07/17 12:13:10 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, len);
	i = 0;
	while (i < len && start < ft_strlen((char *)s) \
			&& *(s + start + i) != '\0')
	{
		*(ret + i) = *(s + start + i);
		i++;
	}
	*(ret + len) = '\0';
	return (ret);
}
