/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:28:36 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/16 16:47:00 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_checker(char *str)
{
	int				i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
		{
			if (i < ft_strlen_gnl(str) - 1)
				return (2);
			return (1);
		}
	return (0);
}

static char			*split_at_nl(char **str, char *s2)
{
	char			*ret;
	int				i;
	int				len;

	i = -1;
	len = 0;
	while (s2[len] && s2[len] != '\n')
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (++i < len)
		ret[i] = s2[i];
	if (!(*str = ft_substr_gnl(s2, len + 1, ft_strlen_gnl(s2) - len - 1, *str)))
		return (NULL);
	return (ret);
}

static int			ft_free(char *str, int i)
{
	free(str);
	str = NULL;
	return (i);
}

static int			gnl_be_longboi(int fd, char **line, char **str)
{
	int				ret;
	char			*buf;

	ret = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (read(fd, buf, 0) < 0)
		return (ft_free(buf, -1));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_checker(buf) > 0)
		{
			if (!(*line = ft_strjoin_gnl(*line, split_at_nl(&str[fd], buf), 1)))
				return (-1);
			break ;
		}
		else if (!(*line = ft_strjoin_gnl(*line, buf, 0)))
			return (-1);
	}
	return (ft_free(buf, ret == 0 ? 0 : 1));
}

int					get_next_line(int fd, char **line)
{
	static char		*str[OPEN_MAX];

	*line = ft_strdup_gnl("");
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (str[fd] && ft_checker(str[fd]) > 0)
	{
		free(*line);
		if (!(*line = split_at_nl(&str[fd], str[fd])))
			return (-1);
		return (1);
	}
	else if (str[fd])
	{
		free(*line);
		if (!(*line = ft_strdup_gnl(str[fd])))
			return (-1);
		free(str[fd]);
		str[fd] = NULL;
	}
	return (gnl_be_longboi(fd, line, str));
}
