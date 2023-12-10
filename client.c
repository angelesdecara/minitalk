/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:04:49 by angrodri          #+#    #+#             */
/*   Updated: 2023/12/10 20:51:34 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

static void	byte2bin(char *msg, int pid)
{
	int		i;
	int		counter;
	char	c;

	i = 0;
	counter = 0;
	while (*msg)
	{
		ft_printf("%c %d\n", *msg, pid);
		i = 8;
		c = *msg++;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
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
	byte2bin(argv[2], pid);
	while (1)
		pause();
	return (0);
}
