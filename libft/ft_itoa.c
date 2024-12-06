/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolan <yolan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:00:42 by yolan             #+#    #+#             */
/*   Updated: 2024/10/14 11:13:25 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	static_len(int n)
{
	int	count;

	count = 1;
	while (n < -9 || n > 9)
	{
		n = n / 10;
		count++;
	}
	if (n >= -9 && n < 0)
	{
		count += 1;
	}
	return (count);
}

static char	*static_swap(char *str, int count, int i)
{
	char	temp;

	while (i < count / 2)
	{
		temp = str[i];
		str[i] = str[count - i - 1];
		str[count - i - 1] = temp;
		i++;
	}
	return (str);
}

static char	*static_negative(char *str, unsigned int n, int count)
{
	char	temp;
	int		i;

	i = 0;
	str[i++] = '-';
	n *= -1;
	while (i < count)
	{
		str[i] = ((n % 10) + '0');
		n = n / 10;
		i++;
	}
	i = 1;
	while (i <= count / 2)
	{
		temp = str[i];
		str[i] = str[count - i];
		str[count - i] = temp;
		i++;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		i;

	count = static_len(n);
	i = 0;
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	if (n < 0)
		static_negative(str, n, count);
	else
	{
		while (i < count)
		{
			str[i] = ((n % 10) + '0');
			n = n / 10;
			i++;
		}
		str = static_swap(str, count, 0);
		str[count] = '\0';
	}
	return (str);
}
