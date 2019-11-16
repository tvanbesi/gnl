/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 01:29:07 by thomas            #+#    #+#             */
/*   Updated: 2019/11/16 02:04:01 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int
	get_next_line(int fd, char **line)
{
	static char	*buf;
	ssize_t		b;

	if (!buf)
	{
		if (!(buf = (char*)malloc(sizeof(*buf) * (BUFFER_SIZE + 1))))
			return (-1);
		b = read(fd, buf, BUFFER_SIZE);
		buf[b] = '\0';
	}
	else
		; //WORK ON BUFFER
}
