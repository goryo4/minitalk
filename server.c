/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:00:52 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/06 16:28:49 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    reception(int sig)
{
    static int nbr = 0;
    static char c;

    if (sig == SIGUSR1)
        c = (c << 1) | 1;
    else if (sig == SIGUSR2)
        c = c << 1;
    nbr++;
    if (nbr == 8)
    {
        ft_printf("%c", c);
        nbr = 0;
    }
}

int main()
{
    int pid;

    pid = getpid();
    ft_printf("%d\n", pid);
    signal(SIGUSR1, reception);
    signal(SIGUSR2, reception);
    while (1)
        pause();
    return (0);
}
