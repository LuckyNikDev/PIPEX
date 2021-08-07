/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:39:58 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 18:11:15 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pipe	*ft_create_and_init_pipe(int argc, char **argv, char **envp)
{
	t_pipe	*pointer;

	pointer = (t_pipe *) malloc(sizeof(t_pipe));
	if (!pointer)
		ft_error(9);
	pointer->argc = argc;
	pointer->argv = argv;
	pointer->envp = envp;
	pointer->count_iter = 0;
	pointer->index_arg = 2;
	pointer->heredoc_way1 = 0;
	pointer->heredoc_way2 = 0;
	return (pointer);
}

int	**ft_create_mas_pipe(int count)
{
	int	**result;
	int	i;

	i = 0;
	result = (int **) malloc(sizeof(int *) * count + 1);
	if (result == NULL)
		ft_error(9);
	result[count] = NULL;
	while (i < count)
	{
		result[i] = (int *) malloc(sizeof(int) * 2);
		if (pipe(result[i]))
			ft_error(3);
		i++;
	}
	return (result);
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
	else if (error == 8)
		write(2, "Exception error start process", 29);
	else if (error == 9)
		write(2, "Exception error malloc", 22);
	exit(0);
}
