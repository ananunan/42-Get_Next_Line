/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:17:47 by aeberius          #+#    #+#             */
/*   Updated: 2024/07/06 13:22:15 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *result, char *buffer);
static char	*copy_until_newline(char *str);
static void	strcpy_from_newline(char *str);

static char	*read_buffer(int fd, char *result, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		result = ft_strjoin(result, copy_until_newline(buffer));
		strcpy_from_newline(buffer);
		if (ft_strchr(result, '\n'))
			return (result);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		if (result)
			free(result);
		return (NULL);
	}
	return (result);
}

static char	*copy_until_newline(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = (char *)malloc(sizeof(char) * i + 1);
	result[i] = 0;
	while (i-- > 0)
		result[i] = str[i];
	return (result);
}

static void	strcpy_from_newline(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i])
		str[j++] = str[i++];
	while (str[j])
		str[j++] = 0;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*result;

	if (fd < 0)
		return (NULL);
	result = NULL;
	if (buffer[0])
	{
		result = copy_until_newline(buffer);
		strcpy_from_newline(buffer);
		if (ft_strchr(result, '\n'))
			return (result);
	}
	result = read_buffer(fd, result, buffer);
	return (result);
}
