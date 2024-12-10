/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:06:05 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/10 13:58:19 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	value;
	int	s;

	i = 0;
	s = 1;
	value = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + (nptr[i] - 48);
		i++;
	}
	return (value * s);
}

int bytes(char c, int pid)
{
    int i;
    int bits;

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

int main(int argc, char **argv)
{
    int i;
    int pid;
    
    i = 0;
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

