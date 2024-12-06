/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:54:04 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/24 14:21:00 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}*/

char	*ft_strdup_gnl(char *s)
{
	char	*str;
	int		len;
	int		count;

	len = ft_strlen((char *)s);
	count = len;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free(s);
		return (0);
	}
	while (len--)
	{
		*str = *s;
		str++;
		s++;
	}
	*str = '\0';
	return (str - count);
}

/*char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}*/

static char	*ft_invalid_read(int size, char *buffer)
{
	free(buffer);
	if (size == -1)
		return (NULL);
	return (NULL);
}

char	*ft_read(int fd, char *buffer, char *old_line)
{
	int	size;

	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1 || (size == 0 && ft_strlen(old_line) == 0))
		{
			free(old_line);
			old_line = NULL;
			return (ft_invalid_read(size, buffer));
		}
		buffer[size] = '\0';
		old_line = ft_tmp_line(buffer, old_line);
		if (ft_strchr(old_line, '\n') || size == 0)
			break ;
	}
	return (old_line);
}
