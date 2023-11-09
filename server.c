/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:27:33 by angrodri          #+#    #+#             */
/*   Updated: 2023/11/09 21:55:18 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_signal(int signal)
{
	static int	counter;
	static char	message;

	message |= (signal == SIGUSR1);
	counter ++;
	if (counter == 8)
	{
		ft_printf("%c", message);
		counter = 0;
		message = 0;
	}
	else
		message <<= 1;
}

int main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%i", pid);
	signal(SIGUSR1, print_signal);
	signal(SIGUSR2, print_signal);
	while (1)
		pause();
	return (1);
}
