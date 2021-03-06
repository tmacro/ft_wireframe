/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:50:43 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/14 14:22:06 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buf_copy(char **dest, char *src, size_t len)
{
	char *tmp;
	char *trunc;

	if (!**dest)
		*dest = ft_strncpy(ft_strnew(len), src, len);
	else
	{
		trunc = ft_strsub(src, 0, len);
		tmp = *dest;
		*dest = ft_strjoin(*dest, trunc);
	}
}

int		save_fd(const int fd, char *buf, char **obs_fd)
{
	size_t	len;
	char	*start;

	ERR_CNR((start = ft_strchr(buf, '\n')), NULL, 0);
	len = ft_strlen(start + 1);
	obs_fd[fd] = ft_strnew(len);
	ft_strcpy(obs_fd[fd], start + 1);
	return (1);
}

void	load_fd(const int fd, char **buf, char **obs_fd)
{
	*buf = ft_strnew(BUFF_SIZE);
	if ((obs_fd[fd]))
	{
		ft_strcpy(*buf, obs_fd[fd]);
		obs_fd[fd] = 0;
	}
}

int		parse_line(int fd, char **buf, char **line, char **obs_fd)
{
	buf_copy(line, *buf, ft_strlen_d(*buf, '\n'));
	ERR_CNR(save_fd(fd, *buf, obs_fd), 1, 1);
	ft_bzero(*buf, BUFF_SIZE);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		*buf;
	int			bytes_read;
	static char	*obs_fd[MAX_FDS];

	ERR_CNR((fd < 0 || fd == 1 || fd == 2), 1, -1);
	ERR_CNR(line, NULL, -1);
	*line = ft_strnew(0);
	load_fd(fd, &buf, obs_fd);
	ERR_CNR((parse_line(fd, &buf, line, obs_fd)), 1, 1);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)) > -2)
	{
		ERR_CNR(bytes_read, -1, -1);
		BREAK(bytes_read, 0);
		ERR_CNR(parse_line(fd, &buf, line, obs_fd), 1, 1);
	}
	ERR_CNR(**line, 0, 0);
	return (1);
}
