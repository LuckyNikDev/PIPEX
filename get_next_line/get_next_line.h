/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:22:38 by bsailor           #+#    #+#             */
/*   Updated: 2021/08/06 18:22:39 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
int		get_next_line_read(int fd, char **line, char **stat);
void	ft_strlcpy_get(char *dst, const char *src, size_t size);
size_t	ft_strchr_get(const char *s, int c);
char	*ft_strjoin_get(char *s1, char *s2, long n);
char	*ft_substr_fr(char *s, unsigned int start, size_t len);
size_t	ft_strlen_get(const char *str);
char	*ft_substr_get(char *s, unsigned int start, size_t len);
int		have_stat(char **line, char **stat);
int		dont_have_stat(char **line, char **stat, long count, char *buf);

#endif