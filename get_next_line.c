/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:49:06 by tvanbesi          #+#    #+#             */
/*   Updated: 2019/11/15 00:05:58 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int
	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE];
	ssize_t	b;

	if ((b = read(fd, buf, BUFFER_SIZE) != -1))
		if (b)
			for (unsigned int i = 0; i < 32; i++)
				printf("%c", buf[i]);
		else
			;	//END OF FILE
	else
		return (b);
	return (1);
}

#include <fcntl.h>

int
	main(void)
{
	char	**line;
	int		fd = open("test.txt", O_RDONLY);
	
	get_next_line(fd, line);
	close(fd);
}
