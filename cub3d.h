/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:41:20 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/15 19:20:34 by ade-la-c         ###   ########.fr       */
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

# include "includes/libft/libft.h"
# include "includes/get_next_line/get_next_line.h"
# include "includes/mlx/mlx.h"

# define MS 0.1
# define RS 0.1

# define XEVENT_KEYPRESS 2
# define XEVENT_KEYRELEASE 3
# define XEVENT_EXIT 17

# define KEYCODE_ESC 53
# define KEYCODE_RIGHTARROW 124
# define KEYCODE_LEFTARROW 123
# define KEYCODE_W 13
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2

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

typedef struct		s_tex
{
	void			*img;
	int				*addr;
	int				height;
	int				width;
	int				line_length;
	int				bit;
	int				endian;
}					t_tex;

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
	t_list			*lst;
	t_tex			north;
	t_tex			south;
	t_tex			west;
	t_tex			east;
}					t_file;

typedef struct		s_mlibx
{
	int				bits_per_pxl;
	int				line_length;
	int				endian;
	int				*addr;
	void			*mlx;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				pxl_line;
}					t_mlibx;

typedef struct		s_map
{
	t_coord			iter;
	t_vec			pos;
	int				width;
	int				height;
	int				**map;
	t_rgb			wall_color;
	int				position;
	int				**actual_pos;
}					t_map;

typedef struct		s_pos
{
	int				x;
	t_vec			dir;
	t_vec			old_dir;
	t_vec			plane_cam;
	t_vec			old_pl_cam;
	t_vec			camera;
}					t_pos;

typedef struct		s_glb
{
	t_tex			*tex;
	t_file			*file;
	t_mlibx			*mlibx;
	t_map			*map;
	t_pos			*pos;
}					t_glb;

void				t_rgb_init(t_rgb *rgb);
void				t_coord_init(t_coord *coord);
void				t_vec_init(t_vec *vec);
void				exit_error(char *error);
int					ft_isspace(char c);

/*
**	FILE PARSING
*/

t_glb				*parsing(char *filepath, t_glb *glb);
void				parse_res(char *line, t_coord *res, t_file *file, int i);
void				parse_path(char *line, char **path, t_file *file, int i);
void				parse_rgb(char *line, t_rgb *rgb, t_file *file, int i);
t_map				*map_parsing(t_list *lst, t_glb *glb);
void				dir_to_vec(int i, t_pos *pos);
void				verif_map(t_map *map);

/*
**	les hook et les loop
*/

void				hook_loop(int ac, t_glb *glb);
void				free_file(t_file *file, char *str);

/*
**	VISUAL PART
*/

void				mv_forward(t_pos *pos, t_map *map);
void				mv_backward(t_pos *pos, t_map *map);
void				mv_left(t_pos *pos, t_map *map);
void				mv_right(t_pos *pos, t_map *map);
void				rotate_right(t_pos *pos);
void				rotate_left(t_pos *pos);

void	imprimer_file(t_file *file);

#endif
