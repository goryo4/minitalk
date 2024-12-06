/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:03:11 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/21 16:02:07 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*strs;
	unsigned char		*strd;
	unsigned int		i;

	strs = src;
	strd = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n > i)
	{
		strd[i] = strs[i];
		i++;
	}
	return ((unsigned char *)strd);
}
