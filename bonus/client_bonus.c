/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:06:05 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/10 15:20:36 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	bytes(char c, int pid)
{
	int	i;
	int	bits;

	i = 7;
	while (i >= 0)
	{
		bits = (c >> i) & 1;
		if (bits == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(350);
		i--;
	}
	return (0);
}

void	recep(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("server read 1\n");
	else if (sig == SIGUSR2)
		ft_printf("server read 0\n");
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	signal(SIGUSR1, recep);
	signal(SIGUSR2, recep);
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		bytes(argv[2][i], pid);
		i++;
	}
	bytes('\n', pid);
	bytes('\0', pid);
	return (0);
}
