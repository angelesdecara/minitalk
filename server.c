/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:21:43 by angrodri          #+#    #+#             */
/*   Updated: 2023/12/10 21:00:11 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void sig_handler(int signum, siginfo_t *info, void* context)
{
	static int 	i;
	static char c;
	pid_t		c_pid;
	
	(void) context;
	if (!c_pid)
		c_pid = info->si_pid;
	if (g_server == 0)
		ft_printf("pid number %i while i = %d  and c =  %c \n", info->si_pid ,i, c);
	/*adding send signum and address of c to bin2char
	bin_to_char(signum, &c);
	ft_printf("c = %c\n", c);*/

	c |= (signum == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(c_pid, SIGUSR2);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(c_pid, SIGUSR1);
	}
	else
	   c <<= 1;	
}

int main(void)
{
	struct sigaction 	action;

	ft_printf("server id is = %i\n", getpid());
	ft_bzero(&action, sizeof(action));
	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);

	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
}
