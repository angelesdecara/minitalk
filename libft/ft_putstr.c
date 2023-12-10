/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:50:15 by angrodri          #+#    #+#             */
/*   Updated: 2023/12/10 15:31:08 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!(s == NULL))
	{
		i = 0;
		while (*(s + i) != '\0')
			i++;
		write (1, s, i);
		return (i);
	}
	else
	{
		write (1, "(null)", 6);
		return (6);
	}
}
