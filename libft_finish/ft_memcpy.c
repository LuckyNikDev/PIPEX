/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:41:08 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/18 12:09:46 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*buf;
	char	*sr;

	if (dest == NULL && src == NULL)
		return (dest);
	buf = dest;
	sr = (char *)src;
	while (n > 0)
	{
		*(char *)dest = *sr;
		dest++;
		sr++;
		n--;
	}
	return (buf);
}
