/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:06:43 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/12 12:09:13 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str, char *err)
{
	free (str);
	ft_printf("%s\n", err);
	exit (EXIT_FAILURE);
}

char	*strjoin(char *s1, char c)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		ft_error(s1, ERR_MALLOC);
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
	else if (sig == SIGINT)
		exit(EXIT_FAILURE);
	nbr++;
	if (nbr == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s", str);
			free (str);
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
	if (signal(SIGUSR1, reception) == SIG_ERR)
		ft_error(NULL, ERR_SIG);
	if (signal(SIGUSR2, reception) == SIG_ERR)
		ft_error(NULL, ERR_SIG);
	if (signal(SIGINT, reception) == SIG_ERR)
		ft_error(NULL, ERR_SIG);
	while (1)
		pause();
	return (0);
}
