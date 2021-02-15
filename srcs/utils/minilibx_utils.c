/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:43:13 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/15 17:16:11 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
**	minilibx_setup appelle les fonctions de la mlx pour setup cub3D
*/

void					minilibx_setup(t_mlibx *mlibx, t_file *file)
{
	if ((mlibx->mlx_win = mlx_new_window(mlibx->mlx_ptr, file->r.x, file->r.y,
	"CUB3D")) == NULL)
		free_file(file, "MLX : crash");
	if ((mlibx->img = mlx_new_image(mlibx->mlx_ptr, file->r.x, file->r.y))
	== NULL)
		return ;
	if ((mlibx->addr = (int *)mlx_get_data_addr(mlibx->img, mlibx->bits_per_pxl,
	mlibx->line_length, mlibx->endian)) == NULL)
		return ;
	mlibx->pxl_line = mlibx->line_length / (mlibx->bits_per_pxl / 8);
}
