/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sigaction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:54:57 by angrodri          #+#    #+#             */
/*   Updated: 2023/11/25 22:00:38 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

volatile sig_atomic_t	g_client;

void	sig_handler(int signalid, siginfo_t *info, char* pid)
{
	static int	counter;

	/* client? could print signal intercepted
	//if (signal == SIGINT)
	//	ft_printf("\nIntercepted SIGINT!\n");*/
	/* folowing medium oduwoledare*/
	info->si_pid = signalid;
	g_client = 1;
	if (signalid == SIGUSR2)
		counter++;
	else if (signalid == SIGUSR1)
	{
		ft_printf("bytes = %i\n", counter/8); //bytes);
		counter = 0;
	}
	/* v0 */
	counter = 0;
	while (counter < 8)
	{
		if ((message >> counter) & 1)
			kill(ft_atoi(pid), SIGUSR1);
		else
			kill(ft_atoi(pid), SIGUSR2);
		counter++;
	}
}

void	set_signal_action(int pid)
{
	struct sigaction	act; //sigaction structure 

	ft_memset(&act, 0x00, sizeof(act)); /*set all structure bits to 0 to avoid errors due to uninitialised vars*/
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &sig_handler; /*signal handler action*/
	act.sa_flags = SA_SIGINFO;
	sigaction(pid, &act, NULL); /* apply the action in the structure to SIGINT signal, ctrl-c*/
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		ft_printf("Wrong number of input parameters");
		return (0);
	}
	pid = ft_atoi(argv[1]);

	set_signal_action(pid);
	while (1)
		pause();
	return (0);
}
