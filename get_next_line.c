/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:48:05 by lmontes-          #+#    #+#             */
/*   Updated: 2023/02/27 22:43:35 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stack_buffer(char *next_line, char *reading)
{
	char	*buffered;

	if (!reading)
		buffered = NULL;
	else
		buffered = ft_strjoin(next_line, reading);
	free(next_line);
	return (buffered);
}

char	*extract_line(int fd, char *next_line)
{
	char	*reading;
	char	*tmp;
	int		n_read;

	if (!next_line)
		next_line = ft_calloc(1, sizeof(char));
	reading = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!reading)
		return (NULL);
	n_read = BUFFER_SIZE;
	while (n_read)
	{
		tmp = reading;
		while (*tmp)
		{
			*tmp = 0;
			tmp++;
		}
		n_read = read(fd, reading, BUFFER_SIZE);
		next_line = stack_buffer(next_line, reading);
		if (next_line[0] && ft_strchr(next_line, '\n'))
			break ;
	}
	free (reading);
	return (next_line);
}

static char	*split_line(char *next)
{
	char	*line;
	int		line_len;

	if (!next[0])
		return (NULL);
	line_len = 0;
	while (next[line_len] != '\n' && next[line_len])
		line_len++;
	line = ft_calloc(line_len + 2, sizeof(char));
	ft_memcpy(line, next, line_len + 1);
	return (line);
}

static char	*keep_for_next(char *next_line)
{
	char	*tmp;
	char	*tail;
	int		len;

	tmp = ft_strchr(next_line, '\n');
	if (!tmp)
	{
		free(next_line);
		return (NULL);
	}
	tmp++;
	len = ft_strlen(tmp);
	tail = ft_calloc(len + 1, sizeof(char));
	ft_memcpy(tail, tmp, len);
	free(next_line);
	return (tail);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (next_line)
		{
			free(next_line);
			next_line = NULL;
		}
		return (NULL);
	}
	next_line = extract_line(fd, next_line);
	line = split_line(next_line);
	next_line = keep_for_next(next_line);
	return (line);
}
