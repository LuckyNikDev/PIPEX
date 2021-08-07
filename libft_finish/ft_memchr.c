/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:06:28 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/22 19:45:02 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char	*ar;

	ar = (char *)arr;
	while (n > 0)
	{
		if (*ar == (char)c)
			return (ar);
		ar++;
		n--;
	}
	return (NULL);
}
