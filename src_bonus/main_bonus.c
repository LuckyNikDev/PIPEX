/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:40:13 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/07 13:09:58 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		id;
	t_pipe	*pointer;

	if (argc < 5)
		ft_error(7);
	pointer = ft_create_and_init_pipe(argc, argv, envp);
	pointer->fd = ft_create_mas_pipe(argc - 4);
	if (ft_strncmp(argv[1], "here_doc", 10))
		ft_heredoc_way(pointer);
	while (pointer->count_iter < (pointer->argc - 3))
	{
		id = fork();
		if (id == -1)
			ft_error(4);
		if (id == 0)
			ft_start_process(pointer);
		else
			ft_main_util(pointer);
	}
	wait(NULL);
	exit(0);
}

void	ft_read_heredoc(t_pipe *pointer)
{
	char	*line;

	while (1)
	{
		write(0, "pipe heredoc> ", 14);
		get_next_line(0, &line);
		if (ft_strncmp(line, pointer->stop_word, \
		ft_strlen(pointer->stop_word) + 1))
			break ;
		write(pointer->fd[0][1], line, ft_strlen(line));
		write(pointer->fd[0][1], "\n", 1);
		free(line);
	}
	close(pointer->fd[0][1]);
	exit(0);
}

void	ft_start_process(t_pipe *pointer)
{
	char	*path;

	if (pointer->heredoc_way1)
		ft_read_heredoc(pointer);
	ft_change_fd(pointer);
	path = ft_find_path(pointer->envp, \
	pointer->argv[pointer->index_arg]);
	execve(path, ft_split(pointer->argv[pointer->index_arg], ' '), \
	pointer->envp);
	ft_error(8);
}

void	ft_change_fd(t_pipe *pointer)
{
	if (pointer->count_iter == 0)
	{
		if (dup2(open(pointer->argv[1], O_RDONLY), 0) == -1 \
		|| dup2(pointer->fd[0][1], 1) == -1)
			ft_error(6);
	}
	else if (pointer->count_iter < pointer->argc - 4)
	{
		close(pointer->fd[pointer->count_iter][0]);
		if (dup2(pointer->fd[pointer->count_iter - 1][0], 0) == -1 \
		|| dup2(pointer->fd[pointer->count_iter][1], 1) == -1)
			ft_error(6);
	}
	else
		ft_change_fd_util(pointer);
}

void	ft_change_fd_util(t_pipe *pointer)
{
	if (pointer->heredoc_way2)
	{
		if (dup2(open(pointer->argv[pointer->argc - 1], \
		O_WRONLY | O_APPEND | O_CREAT, S_IWRITE | S_IREAD), 1) \
		== -1 || dup2(pointer->fd[pointer->count_iter - 1][0], 0) == -1)
			ft_error(6);
	}
	else if (dup2(open(pointer->argv[pointer->argc - 1], \
	O_WRONLY | O_TRUNC | O_CREAT, S_IWRITE | S_IREAD), 1) == -1 || \
	dup2(pointer->fd[pointer->count_iter - 1][0], 0) == -1)
		ft_error(6);
}
