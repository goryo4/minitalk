/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:01:31 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/21 16:02:26 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*strs;
	unsigned char	*strd;
	unsigned int	i;

	strs = (unsigned char *)src;
	strd = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		while (n > i)
		{
			strd[i] = strs[i];
			i++;
		}
	}
	else
	{
		while (n--)
			strd[n] = strs[n];
	}
	return (dest);
}
