/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:27:33 by angrodri          #+#    #+#             */
/*   Updated: 2023/10/27 21:22:35 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_signal(int signal)
{
	int	counter;
	int	c;

	if (signal == SIGUSR1)

}

int main(void)
{
	pid_t	pid;

	pid = getpid();
	while (1)
	{
		write(1, "", 1);
		ft_printf("%s \n%d\n","pid_server",pid);
		signal(SIGUSR1, ft_print_signal);
		sleep(1);
	}
	return (1);
}
