/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:58:52 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/08 16:59:09 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!big && len == 0)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (*big && len--)
	{
		while ((big[j] == little[i]) && i <= len)
		{
			i++;
			j++;
			if (little[i] == '\0')
				return ((char *)big);
		}
		i = 0;
		j = 0;
		big++;
	}
	return (0);
}
