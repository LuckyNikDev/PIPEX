/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:12:33 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 15:12:34 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int error)
{
	if (error == 1)
		write(2, "Exception path not found", 24);
	else if (error == 2)
		write(2, "Exception comand not found", 26);
	else if (error == 3)
		write(2, "Exception create pipe", 21);
	else if (error == 4)
		write(2, "Exception fork", 14);
	else if (error == 5)
		write(2, "Error open file", 15);
	else if (error == 6)
		write(2, "Exception dup", 13);
	else if (error == 7)
		write(2, "Exception count arguments", 25);
	exit(0);
}
