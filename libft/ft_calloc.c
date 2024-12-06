/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:04:35 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/09 17:00:11 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if ((!nmemb) || (!size))
		return (malloc(0));
	if ((size > ((size_t) - 1) / nmemb))
		return (0);
	tab = malloc(size * nmemb);
	if (!tab)
		return (0);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}
