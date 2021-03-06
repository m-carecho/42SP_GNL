/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:46:17 by mcarecho          #+#    #+#             */
/*   Updated: 2021/10/12 21:41:26 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*concat_all(int end, char **buffer_lists, t_bool fl);
static char	*read_text(char **buffer_lists, char *buffer, int fd);
static void	free_ptr(char **ptr);

char	*get_next_line(int fd)
{
	static char	*buffer_lists[MAX_FD + 1];
	char		*buffer;
	char		*resf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (!buffer_lists[fd])
		buffer_lists[fd] = ft_strdup("");
	resf = read_text(&buffer_lists[fd], buffer, fd);
	free_ptr(&buffer);
	return (resf);
}

static void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*read_text(char **buffer_lists, char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*res;

	res = ft_strchr(*buffer_lists, '\n');
	if (res != NULL)
		return (concat_all(res - *buffer_lists + 1, buffer_lists, TRUE));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (concat_all(bytes_read, buffer_lists, FALSE));
	buffer[bytes_read] = 0;
	tmp = ft_strjoin(*buffer_lists, buffer);
	free_ptr(buffer_lists);
	*buffer_lists = tmp;
	return (read_text(buffer_lists, buffer, fd));
}

static char	*concat_all(int end, char **buffer_lists, t_bool fl)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (end <= 0 && fl == FALSE)
	{
		if (**buffer_lists == '\0')
		{
			free_ptr(buffer_lists);
			return (NULL);
		}
		res = *buffer_lists;
		*buffer_lists = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer_lists, end, BUFFER_SIZE);
	res = *buffer_lists;
	res[end] = 0;
	*buffer_lists = tmp;
	return (res);
}
