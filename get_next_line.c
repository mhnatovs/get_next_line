/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:16:37 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/08/25 11:13:39 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	add_part(char **remainder, char *part_str, size_t bytes_read);
static char	*free_and_null(char **remainder);
static void	update_remainder(char **remainder);
static char	*extract_line(char *remainder);

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_null(&remainder));
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = 0;
		if (!add_part(&remainder, buf, bytes_read))
			return (free_and_null(&remainder));
	}
	line = extract_line(remainder);
	if (!line)
		return (free_and_null(&remainder));
	update_remainder(&remainder);
	return (line);
}

static int	add_part(char **remainder, char *part_str, size_t bytes_read)
{
	char	*temp;
	size_t	old_lenth;

	if (*remainder)
		old_lenth = ft_strlen(*remainder);
	else
		old_lenth = 0;
	temp = malloc(old_lenth + bytes_read + 1);
	if (!temp)
		return (0);
	if (*remainder)
	{
		ft_memcpy(temp, *remainder, old_lenth);
		free(*remainder);
	}
	ft_memcpy(temp + old_lenth, part_str, bytes_read);
	temp[old_lenth + bytes_read] = '\0';
	*remainder = temp;
	return (1);
}

static char	*free_and_null(char **remainder)
{
	if (*remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
	return (NULL);
}

static void	update_remainder(char **remainder)
{
	char	*left;
	size_t	i;

	i = 0;
	if (!*remainder)
		return ;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	if ((*remainder)[i] == '\0')
	{
		free(*remainder);
		*remainder = NULL;
		return ;
	}
	left = ft_substr(*remainder, i, ft_strlen(*remainder) - i);
	free(*remainder);
	*remainder = left;
}

static char	*extract_line(char *remainder)
{
	size_t	i;

	i = 0;
	if (!remainder || !remainder[0])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	return (ft_substr(remainder, 0, i));
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		fprintf(stderr, "Usage: %s test_file.txt \n", argv[0]);
// 		return 1;
// 	 }

// 	int fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return 1;
// 	}

// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return 0;
// }