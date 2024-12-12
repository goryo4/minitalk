/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:06:05 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/12 12:06:45 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit (EXIT_FAILURE);
}

int	bytes(char c, int pid)
{
	int	i;
	int	bits;

	i = 7;
	while (i >= 0)
	{
		bits = (c >> i) & 1;
		if (bits == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error(ERR_KILL);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error(ERR_KILL);
		}
		usleep(550);
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
		error(ERR_ARGC);
	pid = ft_atoi(argv[1]);
	if (pid == 0 || pid == -1)
		error(ERR_PID);
	while (argv[2][i])
	{
		bytes(argv[2][i], pid);
		i++;
	}
	bytes('\n', pid);
	bytes('\0', pid);
	return (0);
}
