/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:06:43 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/10 15:49:29 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*strjoin(char *s1, char c)
{
	char	*str;
	int		len;
	int		i;

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

void	reception(int sig)
{
	static int	nbr = 0;
	static char	c;
	static char	*str = NULL;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = c << 1;
	nbr++;
	if (nbr == 8)
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
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, reception);
	signal(SIGUSR2, reception);
	while (1)
		pause();
	return (0);
}
