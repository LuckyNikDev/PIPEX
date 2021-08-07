/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:13 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 18:06:38 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	id;

	if (argc != 5)
		ft_error(7);
	if (pipe(fd))
		ft_error(3);
	id = fork();
	if (id == -1)
		ft_error(4);
	if (id == 0)
		ft_start_first_process(argv, envp, fd);
	else
		ft_start_second_process(argv, envp, fd);
	return (0);
}

void	ft_start_first_process(char **argv, char **envp, int *fd)
{
	char	*path;

	close(fd[0]);
	if (dup2(open(argv[1], O_RDONLY), 0) == -1 || dup2(fd[1], 1) == -1)
		ft_error(6);
	close(fd[1]);
	path = ft_find_path(envp, argv[2]);
	execve(path, ft_split(argv[2], ' '), envp);
}

void	ft_start_second_process(char **argv, char **envp, int *fd)
{
	int		id;
	char	*path;

	wait(NULL);
	id = fork();
	if (id == -1)
		ft_error(4);
	if (id == 0)
	{
		close(fd[1]);
		if (dup2(open(argv[4], O_WRONLY | O_TRUNC | \
		O_CREAT, S_IREAD), 1) == -1 || dup2(fd[0], 0) == -1)
			ft_error(6);
		close(fd[0]);
		path = ft_find_path(envp, argv[3]);
		execve(path, ft_split(argv[3], ' '), envp);
	}
}

char	*ft_find_path(char **envp, char *cmd_name)
{
	char	**result_split;
	char	*result_join;
	char	*result_join_two;
	int		i;

	result_split = ft_split(ft_find_path_util(envp), ':');
	i = 0;
	while (result_split[i])
	{
		result_join = ft_strjoin(result_split[i], "/");
		result_join_two = ft_strjoin(result_join, (ft_split(cmd_name, ' '))[0]);
		free(result_join);
		if (!(access(result_join_two, 0)) && !(access(result_join_two, 1)))
			return (result_join_two);
		free(result_join_two);
		i++;
	}
	ft_error(2);
	return (NULL);
}

char	*ft_find_path_util(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4))
			return (envp[i]);
		i++;
	}
	ft_error(1);
	return (NULL);
}
