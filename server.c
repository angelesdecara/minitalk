/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:27:33 by angrodri          #+#    #+#             */
/*   Updated: 2023/11/25 21:07:17 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void* context) /*we may need to add something for ACK*/
{
	(void)	context;

	ft_printf("\n Return message received by %d\n", signum);
	info->si_pid = signum;//ft_atoi(signum);
}
void	print_signal(int signal)
{
	static int	counter;
	static char	message;

	/* server shall receive signal and show asap*/
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
	pid_t				pid;
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sig_handler;
	sigemptyset(&act.sa_mask);

	pid = getpid();
	ft_printf("%i", pid);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
