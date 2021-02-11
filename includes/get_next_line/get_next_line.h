/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:08:45 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/16 16:47:42 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

int				get_next_line(int fd, char **line);

int				ft_strlen_gnl(const char *str);
char			*ft_strjoin_gnl(char *s1, char *s2, int b);
char			*ft_strdup_gnl(const char *s1);
char			*ft_substr_gnl(char *s, int start, int len, char *str);

#endif
