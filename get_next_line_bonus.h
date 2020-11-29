/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:49:29 by tvanbesi          #+#    #+#             */
/*   Updated: 2019/11/26 17:20:12 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_buf
{
	int				fd;
	char			*buf;
	size_t			ofs;
	ssize_t			ltr;
	struct s_buf	*next;
}					t_buf;

char				*ft_strxtd(char *line, const char *buf, size_t n);
int					get_next_line(int fd, char **line);
ssize_t				ft_strnlchr(const char *s, size_t ofs);
int					ft_rmelem(t_buf **lbuf, int r, int fd);

#endif
