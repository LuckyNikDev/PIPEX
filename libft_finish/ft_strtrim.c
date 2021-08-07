/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:34:34 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/20 19:08:43 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_one(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*result;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		result = ft_strchr(set, s1[i]);
		if (result == NULL)
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	i = ft_one(s1, set);
	s1 = s1 + i;
	len = len - i;
	i = 0;
	while (i < len)
	{
		result = ft_strchr(set, s1[len - i - 1]);
		if (result == NULL)
			break ;
		i++;
	}
	result = (char *)malloc(len - i + 1);
	if (result == NULL)
		return (NULL);
	len = ft_strlcpy(result, s1, len - i + 1);
	return (result);
}
