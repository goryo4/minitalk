/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:22:39 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/21 16:01:47 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;
	unsigned int		i;

	src1 = s1;
	src2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n - 1 > i)
	{
		if (src1[i] || src1[i] != src2[i])
			break ;
		i++;
	}
	return (src1[i] - src2[i]);
}
