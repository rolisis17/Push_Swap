/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:25:40 by dcella-d          #+#    #+#             */
/*   Updated: 2022/12/06 11:18:02 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	int			posnextline;
	static char	*keep;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (gnl_check(keep) == 0)
		keep = full_line(fd, keep);
	if (!keep || keep[0] == '\0')
	{
		free (keep);
		keep = NULL;
		return (NULL);
	}
	posnextline = gnl_check(keep);
	line = makeline(keep, posnextline);
	if (posnextline > 0)
		keep = ft_strjoin(keep, keep + posnextline, -1);
	else
	{
		free (keep);
		keep = NULL;
	}	
	return (line);
}

char	*makeline(char *keep, int posnextline)
{
	int		f;
	char	*line;

	f = -1;
	if (!keep)
		return (NULL);
	if (posnextline == 0)
		posnextline = ft_strlen(keep);
	line = ft_calloc(posnextline + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (keep[++f] && f < posnextline)
		line[f] = keep[f];
	return (line);
}

char	*full_line(int fd, char *keep)
{
	int		f;
	char	*line;

	f = BUFFER_SIZE;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (f > 0)
	{
		if (gnl_check(line) > 0)
			break ;
		f = read(fd, line, BUFFER_SIZE);
		if (f < 0)
		{
			if (keep)
				free (keep);
			keep = NULL;
			break ;
		}
		line[f] = 0;
		keep = ft_strjoin(keep, line, 0);
	}
	free (line);
	return (keep);
}

/* #include <fcntl.h>

int	main(void)
{
	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *str5;
	int fd = open("fuc.txt", O_RDONLY);
	str = get_next_line(fd);
	str2 = get_next_line(-1);
	str3 = get_next_line(fd);
	str4 = get_next_line(-1);
	str5 = get_next_line(fd);
	printf("This is your ass: %s", str);
	free (str);
	printf("This is your ass: %s", str2);
	free (str2);
	printf("This is your ass: %s", str3);
	free (str3);
	printf("This is your ass: %s", str4);
	free (str4);
	printf("This is your ass: %s", str5);
	free (str5);
	close (fd);
	return (0);
} */