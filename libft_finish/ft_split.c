/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:08:30 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/24 13:36:44 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_check(char **result, unsigned int k)
{
	while (--k >= 0)
		free(result[k]);
	free (result);
	return (NULL);
}

char	**ft_splitmake(char **result, char const *s, char c, size_t count)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	len;

	i = 0;
	k = 0;
	while (k < count)
	{
		len = 0;
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i + len] != c && s[i + len] != 0)
			len++;
		result[k] = ft_substr(s, i, len);
		if (result[k] == NULL)
			return (ft_check(result, k));
		i += len;
		k++;
	}
	result[k] = NULL;
	return (result);
}

size_t	ft_counter(char const *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != 0)
		i++;
	while (s[i] != 0)
	{
		while (s[i] != c && s[i] != 0)
			i++;
		count++;
		while (s[i] == c && s[i] != 0)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**result;

	if (s == NULL)
		return (NULL);
	count = ft_counter(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (result != NULL)
		return (ft_splitmake(result, s, c, count));
	return (NULL);
}
