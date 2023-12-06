/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:04:49 by angrodri          #+#    #+#             */
/*   Updated: 2023/12/06 21:11:54 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

int char2bin(char msg, int pid)
{
	int		i;

	i = 8;
	while (i--)
	{
		if ((msg >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	return (1);
}

int	byte2bin(char *msg, int pid)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (msg[i])
	{
		counter += char2bin(msg[i], pid);
		i++;
	}
	counter += char2bin(msg[i], pid);
	return (counter);
}

int main(int argc, char** argv)
{
	int	pid;

	if (argc < 3)
	{
		ft_printf("Wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_printf("Sent %i\n", byte2bin(argv[2], pid));
	return (0);
}
