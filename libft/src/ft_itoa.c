/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:44:28 by angrodri          #+#    #+#             */
/*   Updated: 2023/07/26 20:55:46 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long int	pot10(int n)
{
	unsigned long int	pot;

	pot = 1;
	while (n > 0)
	{
		pot = pot * 10;
		n--;
	}
	return (pot);
}

static unsigned long int	numero(int n)
{
	unsigned long int	ret;

	if (n < 0)
		ret = (-1) * (long int)(n);
	else
		ret = (unsigned long int)n;
	return (ret);
}

static int	dig(unsigned long int n)
{
	unsigned long int	i;
	int					j;

	i = 10;
	j = 0;
	while (n >= i)
	{
		i = i * 10;
		j++;
	}
	j++;
	return (j);
}

char	*ft_itoa(int n)
{
	unsigned long int	nn;
	int					l;
	char				*ret;
	int					i;

	nn = numero(n);
	l = dig(nn);
	i = 0;
	if (n < 0)
		ret = malloc((l + 2) * sizeof(char));
	else
		ret = malloc((l + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
		ret[i++] = '-';
	while (nn >= 10 || l > 1)
	{
		ret[i++] = nn / pot10(--l) + '0';
		nn = nn % pot10(l);
	}
	ret[i++] = nn % 10 + '0';
	ret[i++] = '\0';
	return (ret);
}
