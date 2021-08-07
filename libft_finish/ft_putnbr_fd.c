/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:52:22 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/20 10:29:01 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	s;
	long	nn;

	nn = n;
	if (nn < 0)
	{
		write (fd, "-", 1);
		nn *= -1;
	}
	if (nn > 9)
		ft_putnbr_fd(nn / 10, fd);
	s = (nn % 10) + 48;
	write (fd, &s, 1);
}
