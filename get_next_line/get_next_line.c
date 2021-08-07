/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:22:33 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 18:22:34 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	long		n;
	static char	*stat;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	n = 0;
	*line = NULL;
	if (stat)
	{
		if (have_stat(line, &stat))
			return (1);
	}
	n = get_next_line_read(fd, line, &stat);
	if (n < 0)
		return (-1);
	else if (n > 0)
		return (1);
	else
		return (0);
}

int	have_stat(char **line, char **stat)
{
	long	n;

	*line = ft_substr_fr(*stat, 0, ft_strlen_get(*stat));
	n = ft_strchr_get(*line, 10);
	if (n >= 0)
	{
		*stat = ft_substr_get(*line, (n + 1), ft_strlen_get(*line));
		*line = ft_substr_fr(*line, 0, n);
		return (1);
	}
	*stat = NULL;
	return (0);
}

int	get_next_line_read(int fd, char **line, char **stat)
{
	char	buf[BUFFER_SIZE + 1];
	long	count;
	int		result;

	count = 1;
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
			return (-1);
		buf[count] = '\0';
		result = dont_have_stat(line, stat, count, buf);
		if (result == 0 || result == 1)
		{
			if (result)
				return (1);
			return (0);
		}
	}
	return (0);
}

int	dont_have_stat(char **line, char **stat, long count, char *buf)
{
	long	n;

	n = ft_strchr_get(buf, 10);
	if (n >= 0)
	{
		*line = ft_strjoin_get(*line, buf, n);
		*stat = ft_substr_get(buf, (n + 1), ft_strlen_get(buf));
		return (1);
	}
	else if (count == 0)
	{
		if (*stat != NULL)
			free(*stat);
		if (!(*line))
		{
			*line = malloc(1);
			*line[0] = '\0';
		}
		return (0);
	}
	else
	{
		*line = ft_strjoin_get(*line, buf, n);
		return (-1);
	}
}

char	*ft_substr_fr(char *s, unsigned int start, size_t len)
{
	char	*str;

	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy_get(str, &s[start], len + 1);
	if (s)
		free(s);
	return (str);
}
