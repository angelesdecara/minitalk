/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:38:08 by angrodri          #+#    #+#             */
/*   Updated: 2022/06/30 15:16:24 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		n1;
	int		i;
	int		j;

	i = 0;
	while (i < (int) ft_strlen((char *)s1) && ft_strchr(set,*(s1 + i)) != '\0')
		i++;
	j = 0;
	while (j < (int) ft_strlen((char *) s1) && \
			ft_strchr(set,*(s1 + ft_strlen((char *)s1) - j)) != '\0')
		j++;
	j--;
	n1 = ft_strlen((char *)s1) - i - j;
	if (n1 < 0)
		n1 = 0;
	ret = malloc((n1 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1 + i, n1 + 1);
	return (ret);
}
