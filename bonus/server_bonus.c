/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:06:43 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/12 12:42:20 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		ft_error(NULL, ERR_SIG);
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

void	reception(int sig, siginfo_t *info, void *context)
{
	static int	nbr = 0;
	static char	c;
	static char	*str = NULL;

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
			free (str);
			str = NULL;
		}
		else
			str = strjoin(str, c);
		nbr = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_error(str, ERR_KILL);
	}
	else if (kill(info->si_pid, SIGUSR1) == -1)
		ft_error(str, ERR_KILL);
}

void	ft_finish(int sig)
{
	if (sig == SIGINT)
		exit (EXIT_SUCCESS);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = reception;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error(NULL, ERR_SIG);
	if (signal(SIGINT, ft_finish) == SIG_ERR)
		ft_error(NULL, ERR_SIG);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}
