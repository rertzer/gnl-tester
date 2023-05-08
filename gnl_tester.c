/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:28:39 by rertzer           #+#    #+#             */
/*   Updated: 2022/11/23 11:27:59 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	printf("buffer size :%d\n", BUFFER_SIZE);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
	}
	else
		fd = 0;
	while ((line = get_next_line(fd)))
	{
//		getchar();
		printf("%s", line);
		free(line);
	}
	if (fd)
		close(fd);
	return (0);
}
