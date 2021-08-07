/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:32:59 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 18:05:31 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft_finish/libft.h"
# include "../get_next_line/get_next_line.h"

void	ft_start_first_process(char **argv, char **envp, int *fd);
void	ft_start_second_process(char **argv, char **envp, int *fd);
char	*ft_find_path(char **envp, char *cmd_name);
char	*ft_find_path_util(char **envp);
void	ft_error(int error);

#endif