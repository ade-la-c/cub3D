/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:35:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/04 15:56:49 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	verline function draws walls (top to bottom)
*/

static void				verline(t_glb *glb)
{
	int					i;

	i = -1;
	while (++i < glb->move->draw_start)
		minilibx_pxl_put(glb->mlibx, glb->pos->x, i, glb->map->colorc);
	texture(glb->pos, glb->move, glb->file, glb);
	i = glb->pos->y - 1;
	while (++i < glb->file->r.y)
		minilibx_pxl_put(glb->mlibx, glb->pos->x, i, glb->map->colorf);
	return ;
}

/*
**	start_pos calls a few funcions for the algorythm & display of cub3D,
**	this function also convertd the t_rgb floor & ceiling colors to a
**	u_int32_t variable simplify the code later
*/

static void				start_pos(t_glb *glb, t_file *file)
{
	init_struct(glb->move, glb->map);
	condition_ray(glb->move, glb->map);
	move_square(glb->move, glb->map);
	pxl_to_fill(glb->move, file, glb->map);
	glb->map->colorf = file->f.b + file->f.g * 256 + file->f.r * 65536;
	glb->map->colorc = file->c.b + file->c.g * 256 + file->c.r * 65536;
	verline(glb);
	return ;
}

/*
**	algo_raycasting is main algorythm function
*/

int						algo_raycasting(t_glb *glb)
{
	glb->pos->x = 0;
	glb->spr->zbuff = ft_calloc(sizeof(double), glb->file->r.x);
	if (!glb->spr->zbuff)
		exit_error("calloc : crash");
	while (glb->pos->x < glb->file->r.x)
	{
		glb->pos->camera.x = 2 * (double)glb->pos->x /
							(double)glb->file->r.x - 1;
		glb->move->dir.x = glb->pos->dir.x + glb->pos->plane_cam.x *
							glb->pos->camera.x;
		glb->move->dir.y = glb->pos->dir.y + glb->pos->plane_cam.y *
							glb->pos->camera.x;
		start_pos(glb, glb->file);
		glb->spr->zbuff[glb->pos->x] = glb->move->perp_wall_dist;
		glb->pos->x++;
	}
	img_sprite(glb);
	free(glb->spr->zbuff);
	return (1);
}
