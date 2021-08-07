/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:40:05 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 17:47:01 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_main_util(t_pipe *pointer)
{
	ft_close_fd(pointer);
	pointer->heredoc_way1 = 0;
	(pointer->count_iter)++;
	(pointer->index_arg)++;
}

void	ft_heredoc_way(t_pipe *pointer)
{
	pointer->heredoc_way1 = 1;
	pointer->heredoc_way2 = 1;
	pointer->stop_word = pointer->argv[2];
}

void	ft_close_fd(t_pipe *pointer)
{
	if (pointer->count_iter == 0)
		close(pointer->fd[pointer->count_iter][1]);
	else if (pointer->count_iter < pointer->argc - 4)
	{
		close(pointer->fd[pointer->count_iter - 1][0]);
		close(pointer->fd[pointer->count_iter][1]);
	}
	else
		close(pointer->fd[pointer->count_iter - 1][0]);
}
