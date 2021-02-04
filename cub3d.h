/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:41:20 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/04 20:59:03 by ade-la-c         ###   ########.fr       */
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
# include <float.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				check;
}					t_rgb;

typedef struct		s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_file
{
	t_coord			r;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	t_rgb			f;
	t_rgb			c;
	int				parsed;
	t_list			*map_start;
}					t_file;

typedef struct		s_map
{
	t_coord			iter;
	t_vec			vec;
	int				width;
	int				height;
	int				**real_map;
	t_rgb			wall;
	int				pos;
	int				**actual_pos;
}					t_map;

void				t_rgb_init(t_rgb *rgb);
void				t_vec_init(t_vec *vec);
void				exit_error(char *error);
int					ft_isspace(char c);

void				file_to_lst(char *filepath);
void				parse_lst(t_list **lst);

void				parse_vec(char *line, t_vec *vec, t_file *file, int i);
void				parse_path(char *line, char **path, t_file *file, int i);
void				parse_rgb(char *line, t_rgb *rgb, t_file *file, int i);

void	imprimer_file(t_file *file);

#endif
