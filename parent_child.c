/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:17:57 by angrodri          #+#    #+#             */
/*   Updated: 2023/11/01 17:04:52 by angrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		ft_printf("I'm the child, my internal pid is %d\n", pid);
		ft_printf("Done\n");
	}
	else if (pid > 0)
	{
		ft_printf("I'm the parent, my child's pids is %d\n", pid);
		while (1)
			usleep (1);
	}
	return (0);
}
