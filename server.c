/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolan <yolan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:00:52 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/07 19:18:41 by yolan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void    reception(int sig)
{
    static int nbr = 0;
    static char c;
    static char *str = NULL;

    if (sig == SIGUSR1)
        c = (c << 1) | 1;
    else if (sig == SIGUSR2)
        c = c << 1;
    nbr++;
    if (nbr == 8)
    {
        if (c == '\0')
            printf("%s", str);
        else
            str = ft_strjoin(str, c);
        nbr = 0;
    }
}

int main()
{
    int pid;

    pid = getpid();
    printf("%d\n", pid);
    signal(SIGUSR1, reception);
    signal(SIGUSR2, reception);
    while (1)
        pause();
    return (0);
}
