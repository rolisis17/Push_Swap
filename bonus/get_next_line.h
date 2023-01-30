/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:24:32 by dcella-d          #+#    #+#             */
/*   Updated: 2022/12/04 18:16:52 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strjoin(char *s1, char *s2, int f);

int		ft_strlen(const char *s);

int		gnl_check(char *line);

char	*full_line(int fd, char *keep);

char	*makeline(char *keep, int posnextline);

#endif