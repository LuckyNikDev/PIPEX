/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:22:30 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 18:22:31 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcpy_get(char *dst, const char *src, size_t size)
{
	int				i;

	i = 0;
	if (size != 0)
	{
		size--;
		while (size)
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
}

size_t	ft_strchr_get(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen_get(const char *str)
{
	size_t				count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin_get(char *s1, char *s2, long n)
{
	char	*str;
	int		len;

	if (n < 0)
		n = ft_strlen_get(s2);
	len = ft_strlen_get(s1) + ft_strlen_get(s2);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy_get(str, s1, (ft_strlen_get(s1) + 1));
	ft_strlcpy_get(&(str[ft_strlen_get(s1)]), s2, n + 1);
	if (s1)
		free(s1);
	return (str);
}

char	*ft_substr_get(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (ft_strlen_get(s) < start)
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy_get(str, &s[start], len + 1);
	return (str);
}
