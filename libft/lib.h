/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:30:45 by angrodri          #+#    #+#             */
/*   Updated: 2023/12/10 18:54:48 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
size_t	flen(char *s);
int		ft_putnbr_base(unsigned long int nbr, char *base);
int		ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_atoi(const char *arg);
int		ft_printf(char const *str, ...);
char	*ft_itoa(int n);
int		ft_putptr(unsigned long int ptr);
int		ft_uint_print(unsigned int nbr);

#endif
