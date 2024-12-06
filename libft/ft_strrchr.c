/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:46:57 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/08 15:07:02 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = -1;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			cmp = i;
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	if (cmp == -1)
		return (0);
	while (cmp--)
		s++;
	return ((char *)s);
}
