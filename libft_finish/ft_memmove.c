/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:24:06 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/18 12:10:46 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*buf;
	char	*des;
	char	*sr;

	if (dest == NULL && src == NULL)
		return (dest);
	buf = dest;
	des = (char *)dest;
	sr = (char *)src;
	if (dest > src)
	{
		while (n--)
			des[n] = sr[n];
	}
	else
	{
		while (n > 0)
		{
			*des = *sr;
			des++;
			sr++;
			n--;
		}
	}
	return (buf);
}
