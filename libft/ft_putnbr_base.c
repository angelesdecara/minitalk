/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:28:38 by angrodri          #+#    #+#             */
/*   Updated: 2023/12/06 19:12:16 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}

static int	testbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned long int nbr, char *base)
{
	unsigned int		len;
	unsigned long int	aux;
	int					c;

	len = ft_strlen(base);
	aux = nbr;
	c = 0;
	if (testbase(base) > 0)
	{
		if (aux < len)
		{
			c++;
			write(1, &base[aux], 1);
		}
		else
		{
			c += ft_putnbr_base(aux / len, base);
			c += ft_putnbr_base(aux % len, base);
		}
	}
	return (c);
}
