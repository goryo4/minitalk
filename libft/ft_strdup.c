/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:30:02 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/09 16:03:28 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		count;

	len = ft_strlen((char *)s);
	count = len;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (len--)
	{
		*str = *s;
		str++;
		s++;
	}
	*str = '\0';
	return (str - count);
}
