/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:32:41 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/08 18:04:25 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	if (!dst && size == 0)
		return (0);
	i = ft_strlen(dst);
	j = ft_strlen((char *)src);
	if (size <= i)
		return (size + j);
	j = 0;
	while (src[j] && j + i < size - 1)
	{
		dst[j + i] = src[j];
		j++;
	}
	dst[j + i] = '\0';
	if (j < size)
		j = ft_strlen((char *)src);
	return (j + i);
}
