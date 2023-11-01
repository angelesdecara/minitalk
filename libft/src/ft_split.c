/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:40:03 by angrodri          #+#    #+#             */
/*   Updated: 2022/07/17 11:52:14 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizerem(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != '\0' && s[0] != c)
		j++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			j++;
		i++;
	}
	return (j);
}

static int	nchar(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	return (i);
}

static char	*newword(char const *s, char c)
{
	int		len;
	int		i;
	char	*ret;

	i = 0;
	len = nchar(s, c);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = *(s + i);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;
	int		j;

	ret = (char **)malloc((sizerem(s, c) + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < sizerem(s, c))
	{
		while (*(s + j) == c && *(s + j) != '\0')
			j++;
		ret[i] = newword(s + j, c);
		while (*(s + j) != c && *(s + j) != '\0')
			j++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
