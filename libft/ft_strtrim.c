/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolan <yolan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:26:03 by yolan             #+#    #+#             */
/*   Updated: 2024/10/14 10:58:42 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(char const *s1, char const *set, int i)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	ft_end_cmp(char const *s1, char const *set, int i)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i - 1])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_cmp(s1, set, 0);
	len = ft_end_cmp(s1, set, ft_strlen(s1));
	if (len == 0)
		j = 0;
	str = malloc(sizeof(char) * (len - j + 1));
	if (!str)
		return (0);
	while (j < len)
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
