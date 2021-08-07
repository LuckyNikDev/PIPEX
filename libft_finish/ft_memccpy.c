/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:25:26 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/18 12:07:31 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*sr;

	if (dest == NULL && src == NULL)
		return (dest);
	sr = (char *)src;
	while (n > 0)
	{
		*(char *)dest = *sr;
		if (*sr == (char)c)
			return (dest + 1);
		dest++;
		sr++;
		n--;
	}
	return (NULL);
}
