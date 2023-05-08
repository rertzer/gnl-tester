/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:05:28 by rertzer           #+#    #+#             */
/*   Updated: 2022/11/23 13:28:08 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	int		fd[FOPEN_MAX];
	int		i;
	int		something = 1;
	char	*line;

	printf("buffer size: %d\n", BUFFER_SIZE);

	if (argc > 1)
	{
		for (i = 1 ; i < argc ; i++)
		{
			fd[i] = open(argv[i], O_RDONLY);
			if (fd[i] < 0)
				return (1);
			printf("file %d opened\n", i);
		}
		puts("start reading");
		while (something)
		{
			something = 0;
			for (i = 1 ; i < argc ; i++)
			{
				line = get_next_line(fd[i]);
				if (line)
					something = 1;
				printf("file %d, %s\n", i, line);
				free(line);
			}
		}
		puts("end reading");
		for (i = 1 ; i < argc ; i++)
		{
			close(fd[i]);
			puts("file closed");
		}
	}
	else
	{
		while ((line = get_next_line(0)))
		{
			if (line[0] == '\n')
			{
				free(line);
				break ;
			}
			printf("line %d: %s$", i, line);
			free(line);
			i++;
		}
	}
	return (0);
}
