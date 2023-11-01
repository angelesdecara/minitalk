/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:25:19 by angrodri          #+#    #+#             */
/*   Updated: 2023/07/26 20:55:33 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				len;
	long long int	res;

	i = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		i *= (1 - *str % 43);
		str++;
	}
	len = i;
	i = 0;
	res = 0;
	while (*str > 47 && *str < 58)
	{
		res = (*str - 48) + res * 10;
		if (res > 2147483647 && len == 1)
			return (-1);
		if (res > 2147483648 && len == -1)
			return (0);
		str++;
	}
	return ((int)(len * res));
}
