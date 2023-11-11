/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sigaction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:54:57 by angrodri          #+#    #+#             */
/*   Updated: 2023/11/11 21:19:10 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sig_handler(int signalid, siginfo info, void context)
{
	int			counter;
	static char	message;

	/* client? could print signal intercepted
	//if (signal == SIGINT)
	//	ft_printf("\nIntercepted SIGINT!\n");*/
	/* folowing medium oduwoledare*/
	if signalid == SIGUSR2
		counter++;
	else if signalid == SIGUSR1
		print bytes
	/* v0 */
	counter = 0;
	while (counter < 8)
	{
		if ((message >> counter) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		counter++;
	}
}

void	set_signal_action(void)
{
	struct sigaction	act; //sigaction structure 

	ft_bzero(&act, sizeof(act)); /*set all structure bits to 0 to avoid errors due to uninitialised vars*/
	sigemptyset(act.sa_mask);
	act.sa_handler = &sigint_handler; /*signal handler action*/
	sigaction(SIGINT, &act, NULL); /* apply the action in the structure to SIGINT signal, ctrl-c*/
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

	set_signal_action();
	while (1)
		pause();
	return (0);
}
