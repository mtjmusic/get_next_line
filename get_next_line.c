/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:16:34 by mmusic            #+#    #+#             */
/*   Updated: 2024/10/02 15:34:42 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*out;

	out = s;
	while (n--)
		*out++ = '\0';
}

char	*ft_find(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_read(char *temp, int *bytes_read, int fd, char *line)
{
	char	*a;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (free(temp), NULL);
	*bytes_read = read(fd, temp, BUFFER_SIZE);
	if (*bytes_read <= 0)
	{
		free(temp);
		return (line);
	}
	temp[*bytes_read] = '\0';
	a = ft_strjoin(line, temp);
	free(temp);
	free(line);
	return (a);
}

char	*ft_fill_leftover(char **leftover)
{
	char	*line;

	if (*leftover != NULL)
	{
		line = ft_strdup(*leftover);
		free(*leftover);
		*leftover = NULL;
		return (line);
	}
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_bzero(line, BUFFER_SIZE + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	int			bytes_read;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 0;
	temp = NULL;
	line = ft_fill_leftover(&leftover);
	if (!line)
		return (NULL);
	while (!ft_find(line))
	{
		line = ft_read(temp, &bytes_read, fd, line);
		if (!line)
			return (free(line), NULL);
		if (bytes_read <= 0 && *line)
			return (line[ft_strlen(line)] = '\0', line);
		else if (bytes_read <= 0)
			return (free(line), NULL);
	}
	temp = ft_find(line);
	leftover = ft_strdup(temp + 1);
	return (*(temp + 1) = '\0', line);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening file\n", 19);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}  */
