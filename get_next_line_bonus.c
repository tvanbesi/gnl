/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:58:02 by tvanbesi          #+#    #+#             */
/*   Updated: 2019/11/26 20:06:58 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int
	make_next_line(int fd, char **line, t_buf *tbuf)
{
	ssize_t		pnl;
	ssize_t		b;
	size_t		n;

	if (tbuf->ltr == -1)
		return (0);
	while ((pnl = ft_strnlchr(tbuf->buf, tbuf->ofs)) == -1)
	{
		n = tbuf->ltr ? tbuf->ltr : BUFFER_SIZE - tbuf->ofs;
		if (!(*line = ft_strxtd(*line, tbuf->buf + tbuf->ofs, n)))
			return (-1);
		tbuf->ofs = 0;
		if (!(b = read(fd, tbuf->buf, BUFFER_SIZE)))
			return (0);
		else if (b < BUFFER_SIZE)
			tbuf->ltr = b;
	}
	n = (tbuf->ltr && tbuf->ltr < pnl) ? tbuf->ltr : pnl;
	*line = ft_strxtd(*line, tbuf->buf + tbuf->ofs, n);
	if (n && n == (size_t)tbuf->ltr)
		return (0);
	if (tbuf->ltr)
		tbuf->ltr = tbuf->ltr - (n + 1) == 0 ? -1 : tbuf->ltr - (n + 1);
	tbuf->ofs += n + 1;
	return (1);
}

static void
	ft_lstadd_back(t_buf **head, t_buf *new)
{
	t_buf	*last;

	if (!*head)
		last = NULL;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
	}
	if (!last)
		*head = new;
	else
		last->next = new;
}

static t_buf
	*ft_findfd(int fd, t_buf **lbuf)
{
	t_buf	*tmp;

	tmp = *lbuf;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_buf*)malloc(sizeof(t_buf))))
		return (NULL);
	if (!(tmp->buf = (char*)malloc(BUFFER_SIZE)))
	{
		free(tmp);
		return (NULL);
	}
	tmp->fd = fd;
	tmp->ofs = 0;
	tmp->ltr = 0;
	tmp->next = NULL;
	ft_lstadd_back(lbuf, tmp);
	return (tmp);
}

int
	get_next_line(int fd, char **line)
{
	static t_buf	*lbuf;
	t_buf			*tbuf;
	ssize_t			b;
	int				mnl;

	if (!BUFFER_SIZE || !line || read(fd, NULL, 0) == -1
		|| !(*line = ft_strxtd(NULL, NULL, 0)))
		return (-1);
	if (!(tbuf = ft_findfd(fd, &lbuf)))
		return (-1);
	b = 0;
	if (tbuf->ofs || (b = read(fd, tbuf->buf, BUFFER_SIZE)))
	{
		if (b && b < BUFFER_SIZE)
			tbuf->ltr = (size_t)b;
		if ((mnl = make_next_line(fd, line, tbuf)) == 1)
			return (1);
		else if (mnl == 0)
			return (ft_rmelem(&lbuf, 0, fd));
		else
			return (-1);
	}
	else
		return (ft_rmelem(&lbuf, 0, fd));
}
