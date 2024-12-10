/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:06:43 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/10 15:30:41 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*strjoin(char *s1, char c)
{
	char	*str;
	int		len;
    int     i;

    i = 0;
	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
    free (s1);
	return (str);
}

void    reception(int sig, siginfo_t *info, void *context)
{
    static int nbr = 0;
    static char c;
    static char *str = NULL;
    
    (void)context;
    if (sig == SIGUSR1)
        c = (c << 1) | 1;
    else if (sig == SIGUSR2)
        c = c << 1;
    if (nbr++ == 7)
    {
        if (c == '\0')
        {
           ft_printf("%s", str);
           str = NULL;
        }
        else
            str = strjoin(str, c);
        nbr = 0;
    }
    if (sig == SIGUSR1)
        kill(info->si_pid,SIGUSR1);
    else if (sig == SIGUSR2)
        kill(info->si_pid, SIGUSR2);
}

int main()
{
    int pid;
    struct  sigaction sa;

    sa.sa_sigaction = reception;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    pid = getpid();
    ft_printf("%d\n", pid);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}

