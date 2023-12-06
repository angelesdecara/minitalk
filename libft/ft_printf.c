/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:18:48 by angrodri          #+#    #+#             */
/*   Updated: 2023/12/06 18:38:22 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	printtype(char type, va_list arg)
{
	int	n;

	if (type == '%')
		n = ft_putchar('%');
	if (type == 'd' || type == 'i')
		n = ft_putnbr(va_arg(arg, int));
	if (type == 's')
		n = ft_putstr(va_arg(arg, char *));
	if (type == 'c')
		n = ft_putchar(va_arg(arg, int));
	if (type == 'u')
		n = ft_uint_print(va_arg(arg, unsigned int));
	if (type == 'p')
		n = ft_putptr((unsigned long int)va_arg(arg, void *));
	if (type == 'x')
		n = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	if (type == 'X')
		n = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	return (n);
}

int	ft_printf(char const *str, ...)
{
	va_list	toprint;
	size_t	i;
	int		c;

	va_start(toprint, str);
	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			c++;
		}
		if (str[i] == '%')
		{
			c += printtype(str[i + 1], toprint);
			i++;
		}
		i++;
	}
	va_end(toprint);
	return (c);
}
