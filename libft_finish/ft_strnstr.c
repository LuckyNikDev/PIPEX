/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:46:11 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/22 19:51:46 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*res;
	size_t	n_len;

	res = (char *)haystack;
	if (*needle != '\0')
	{
		res = NULL;
		n_len = ft_strlen(needle);
		while (*haystack != '\0' && len >= n_len)
		{
			if (*haystack == *needle && ft_memcmp(haystack, needle, n_len) == 0)
				return ((char *)haystack);
			len--;
			haystack++;
		}
	}
	return (res);
}
