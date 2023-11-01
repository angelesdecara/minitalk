/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sigaction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:54:57 by angrodri          #+#    #+#             */
/*   Updated: 2023/11/01 19:46:56 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sigint_handler(int signal)
{
	static int	counter;
	static char	message;

	//if (signal == SIGINT)
	//	ft_printf("\nIntercepted SIGINT!\n");
	message |= (signal == SIGUSR1);
	if (counter == 8)
	{
		ft_printf("%c",  message);
		counter = 0;
		message = 0;
	}
	else
		message >>= 1;
}

void	set_signal_action(void)
{
	struct sigaction	act; //sigaction structure 

	ft_bzero(&act, sizeof(act)); /*set all structure bits to 0 to avoid errors due to uninitialised vars*/
	act.sa_handler = &sigint_handler; /*signal handler set to default action*/
	sigaction(SIGINT, &act, NULL); /* apply the action in the structure to SIGINT signal, ctrl-c*/
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Wrong number of input parameters");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];

	set_signal_action();
	while (1)
		continue;
	return (0);
}
