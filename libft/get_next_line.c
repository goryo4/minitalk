/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:53:15 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/24 15:27:32 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *old_line)
{
	int		i;
	char	*new_line;
	int		size;

	size = 0;
	while (old_line[size] && old_line[size] != '\n')
		size++;
	i = -1;
	new_line = malloc(sizeof(char) * (size + (old_line[size] == '\n') + 1));
	if (!new_line)
		return (NULL);
	while (size - 1 > i++)
		new_line[i] = old_line[i];
	if (old_line[size] && old_line[size] == '\n')
	{
		new_line[i] = '\n';
		new_line[i + 1] = '\0';
	}
	else
		new_line[i] = '\0';
	return (new_line);
}

static char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free (s1);
	return (str);
}

char	*ft_tmp_line(char *buffer, char *old_line)
{
	int		i;
	char	*line;
	int		size;

	size = 0;
	if (!old_line)
	{
		while (buffer[size])
			size++;
		i = 0;
		line = malloc(sizeof(char) * (size + 1));
		if (!line)
			return (NULL);
		while (size > i)
		{
			line[i] = buffer[i];
			i++;
		}
		line[i] = '\0';
	}
	else
		line = ft_join(old_line, buffer);
	return (line);
}

static char	*ft_line(char *old_line)
{
	char	*tmp;
	char	*reset;

	tmp = ft_strchr(old_line, '\n');
	if (tmp == NULL)
	{
		free(old_line);
		return (NULL);
	}
	reset = ft_strdup_gnl(tmp + 1);
	if (reset == NULL)
	{
		free(old_line);
		return (NULL);
	}
	free(old_line);
	return (reset);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*old_line[1024];
	char		*new_line;

	new_line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	old_line[fd] = ft_read(fd, buffer, old_line[fd]);
	if (!old_line[fd])
		return (NULL);
	free (buffer);
	new_line = ft_strcpy(old_line[fd]);
	old_line[fd] = ft_line(old_line[fd]);
	if (old_line[fd] && old_line[fd][0] == '\0')
	{
		free (old_line[fd]);
		old_line[fd] = NULL;
	}
	return (new_line);
}
