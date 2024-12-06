/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:00:25 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/10 11:21:33 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char		*str;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start ;
	if (start > ft_strlen(s))
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (len != 0)
	{
		while (start--)
			s++;
		while (i < len && *s)
		{
			str[i] = *(unsigned char *)s++;
			i++;
		}
	}
	str[i] = '\0';
	return ((char *)str);
}
