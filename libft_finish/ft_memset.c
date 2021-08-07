/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:26:43 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/22 17:40:39 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{	
	size_t			i;
	void			*rr;

	rr = destination;
	i = 0;
	while (i < n)
	{
		*((char *)destination) = c;
		destination++;
		i++;
	}
	return (rr);
}
