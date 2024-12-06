/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolan <yolan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:24:39 by yolan             #+#    #+#             */
/*   Updated: 2024/10/14 11:20:13 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_stlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c)
		s++;
	while ((s[i] != c) && (s[i]))
		i++;
	return (i);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && (s[i] != c))
		{
			count++;
			while (s[i] && (s[i] != c))
				i++;
		}
	}
	return (count);
}

static void	*ft_free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static char	**ft_cpy(char const *s, char c, char **str, int count)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (count-- > 0)
	{
		j = 0;
		len = ft_stlen(s, c);
		str[i] = malloc(sizeof(char) * (len + 1));
		if (!str[i])
			return (ft_free_tab(str, i));
		while (j < len)
		{
			str[i][j++] = *s;
			s++;
		}
		str[i][j] = '\0';
		i++;
		while (*s == c && c != '\0')
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	str = malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (0);
	while (*s != '\0' && *s == c)
		s++;
	str = ft_cpy(s, c, str, count);
	return (str);
}
