/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:41:20 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/01/21 19:20:20 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct		s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct		s_file
{
	t_vec			r;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	t_rgb			f;
	t_rgb			c;
}					t_file;

void				t_rgb_init(t_rgb *rgb);
void				t_vec_init(t_vec *vec);
void				exit_error(char *error);

void				parse_vec(char *line, t_vec *vec, int i);
void				parse_path(char *line, char **path, int i);
void				parse_rgb(char *line, t_rgb *rgb, int i);

void	imprimer_file(t_file *file);

#endif
