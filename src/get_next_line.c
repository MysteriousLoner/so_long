/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:43:21 by yalee             #+#    #+#             */
/*   Updated: 2023/03/16 16:57:16 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *hold, char *buffer)
{
	char	*dest;

	dest = ft_strjoin1(hold, buffer);
	free(hold);
	return (dest);
}

char	*free_used(char *hold)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	if (!hold[i])
	{
		free(hold);
		return (NULL);
	}
	line = malloc((ft_strlen1(hold) - i + 1) * sizeof(char));
	i = i + 1;
	j = 0;
	while (hold[i])
		line[j++] = hold[i++];
	line[j] = '\0';
	free(hold);
	return (line);
}

char	*ft_final(char *hold)
{
	char	*line;
	int		i;

	i = 0;
	if (!hold[i])
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		line[i] = hold[i];
		i++;
	}
	if (hold[i] && hold[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *hold)
{
	char	*buffer;
	int		s;

	if (!hold)
	{
		hold = malloc(1);
		*hold = '\0';
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	s = 1;
	while (s > 0)
	{
		s = read(fd, buffer, BUFFER_SIZE);
		if (s == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[s] = 0;
		hold = ft_join(hold, buffer);
		if (check_s(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*hold[100000];
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	hold[fd] = read_file(fd, hold[fd]);
	if (!hold[fd])
		return (NULL);
	final = ft_final(hold[fd]);
	hold[fd] = free_used(hold[fd]);
	return (final);
}
