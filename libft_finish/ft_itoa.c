/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:56:29 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/20 12:37:22 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

long	ft_short(char *s, long nn)
{
	s[0] = '-';
	nn *= -1;
	return (nn);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nn;
	int		i;

	i = 0;
	nn = n;
	i = ft_numlen(n);
	s = (char *)malloc(i + 1);
	if (s == NULL)
		return (NULL);
	if (nn == 0)
	{
		s[i] = '\0';
		s[0] = 0 + 48;
		return (s);
	}
	if (nn < 0)
		nn = ft_short(s, nn);
	s[i--] = '\0';
	while (nn != 0)
	{
		s[i--] = (nn % 10) + 48;
		nn /= 10;
	}
	return (s);
}
