/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:59:38 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/08 17:30:56 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (size == 1)
		dst[i] = src[i];
	while (src[j])
	{
		if (i < size - 1 && size)
		{
			dst[i] = src[i];
			i++;
		}
		j++;
	}
	if (i > 0 || j == 0 || size == 1)
		dst[i] = '\0';
	return (j);
}
