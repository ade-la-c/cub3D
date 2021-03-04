/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:43:13 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/04 15:56:37 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	image function transforms the .xpm files
*/

void				minilibx_get_image(t_mlibx *mlibx, t_file *file)
{
	if (!(file->no.img = mlx_xpm_file_to_image(mlibx->mlx_ptr, file->no.path,
		&file->no.width, &file->no.height)))
		exit_error("FILE : Error in texture path (NO)");
	if (!(file->so.img = mlx_xpm_file_to_image(mlibx->mlx_ptr, file->so.path,
		&file->so.width, &file->so.height)))
		exit_error("FILE : Error in texture path (SO)");
	if (!(file->we.img = mlx_xpm_file_to_image(mlibx->mlx_ptr, file->we.path,
		&file->we.width, &file->we.height)))
		exit_error("FILE : Error in texture path (WE)");
	if (!(file->ea.img = mlx_xpm_file_to_image(mlibx->mlx_ptr, file->ea.path,
		&file->ea.width, &file->ea.height)))
		exit_error("FILE : Error in texture path (EA)");
	if (!(file->s.img = mlx_xpm_file_to_image(mlibx->mlx_ptr, file->s.path,
		&file->s.width, &file->s.height)))
		exit_error("FILE : Error in texture path (S)");
	file->no.addr = (int *)mlx_get_data_addr(file->no.img, &file->no.bit,
		&file->no.line_length, &file->no.endian);
	file->so.addr = (int *)mlx_get_data_addr(file->so.img, &file->so.bit,
		&file->so.line_length, &file->so.endian);
	file->we.addr = (int *)mlx_get_data_addr(file->we.img, &file->we.bit,
		&file->we.line_length, &file->we.endian);
	file->ea.addr = (int *)mlx_get_data_addr(file->ea.img, &file->ea.bit,
		&file->ea.line_length, &file->ea.endian);
	file->s.addr = (int *)mlx_get_data_addr(file->s.img, &file->s.bit,
		&file->s.line_length, &file->s.endian);
}

/*
**	Pixel's color
*/

void				minilibx_pxl_put(t_mlibx *mlibx, int x, int y, u_int32_t c)
{
	(void)c;
	(mlibx->addr)[y * (mlibx->pxl_line) + x] = c;
	return ;
}

/*
**	minilibx_setup appelle les fonctions de la mlx pour setup cub3D
*/

void				minilibx_setup(t_mlibx *mlibx, t_file *file)
{
	if (!mlibx->mlx_ptr)
		exit_error("MLX : crash");
	if ((mlibx->mlx_win = mlx_new_window(mlibx->mlx_ptr, file->r.x, file->r.y,
	"CUB3D")) == NULL)
	{
		free(file);
		exit_error("MLX : crash");
	}
	if ((mlibx->img = mlx_new_image(mlibx->mlx_ptr, file->r.x, file->r.y))
	== NULL)
		return ;
	if ((mlibx->addr = (int *)mlx_get_data_addr(mlibx->img,
	&mlibx->bits_per_pxl, &mlibx->line_length, &mlibx->endian)) == NULL)
		return ;
	mlibx->pxl_line = mlibx->line_length / (mlibx->bits_per_pxl / 8);
	return ;
}
