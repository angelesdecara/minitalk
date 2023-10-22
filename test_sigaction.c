/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sigaction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:54:57 by angrodri          #+#    #+#             */
/*   Updated: 2023/10/22 18:28:49 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <strings.h>

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
		printf("\nIntercepted SIGINT!\n");
}

void	set_signal_action(void)
{
	struct sigaction	act; //sigaction structure 

	bzero(&act, sizeof(act)); /*set all structure bits to 0 to avoid errors due to uninitialised vars*/
	act.sa_handler = &sigint_handler; /*signal handler set to default action*/
	sigaction(SIGINT, &act, NULL); /* apply the action in the structure to SIGINT signal, ctrl-c*/
}

int	main(void)
{
	set_signal_action();
	while (1)
		continue;
	return (0);
}
