/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:32:59 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 18:16:04 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft_finish/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_pipe
{
	int		**fd;
	int		argc;
	int		count_iter;
	int		index_arg;
	int		heredoc_way1;
	char	*stop_word;
	int		heredoc_way2;
	char	**argv;
	char	**envp;
}			t_pipe;

void		ft_error(int error);
char		*ft_find_path_util(char **envp);
char		*ft_find_path(char **envp, char *cmd_name);
int			**ft_create_mas_pipe(int count);
t_pipe		*ft_create_and_init_pipe(int argc, char **argv, char **envp);
void		ft_close_fd(t_pipe *pointer);
void		ft_start_process(t_pipe *pointer);
void		ft_change_fd(t_pipe *pointer);
void		ft_heredoc_way(t_pipe *pointer);
void		ft_read_heredoc(t_pipe *pointer);
void		ft_change_fd_util(t_pipe *pointer);
void		ft_main_util(t_pipe *pointer);

#endif
