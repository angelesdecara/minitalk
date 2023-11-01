/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:18:16 by angrodri          #+#    #+#             */
/*   Updated: 2022/06/23 16:37:54 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		n1;
	int		n2;

	n1 = ft_strlen((char *)s1);
	n2 = ft_strlen((char *)s2);
	ret = malloc((n1 + n2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (++i < n1)
		*(ret + i) = *(s1 + i);
	i--;
	while (++i < n1 + n2)
		*(ret + i) = *(s2 + i - n1);
	*(ret + i) = '\0';
	return (ret);
}
