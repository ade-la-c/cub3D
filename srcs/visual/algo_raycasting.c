/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:35:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/17 20:02:16 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void				verline(t_glb *glb)
{
	int					i;

	i = -1;
	while (++i < glb->move->draw_start)
		minilibx_pxl_put(glb->mlibx, glb->pos->x, i, glb->map->colorc);
	
	return ;
}

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

int						algo_raycasting(t_glb *glb)
{
	glb->pos->x = 0;
	glb->spr->zbuff = ft_calloc(sizeof(double), glb->file->r.x);
	while (glb->pos->x < glb->file->r.x)
	{
		glb->pos->camera.x = 2 * glb->pos->x / glb->file->r.x - 1;
		glb->move->dir.x = glb->pos->dir.x + glb->pos->plane_cam.x *
			glb->pos->camera.x;
		glb->move->dir.y = glb->pos->dir.y + glb->pos->plane_cam.y *
			glb->pos->camera.x;
		start_pos(glb, glb->file);
		glb->spr->zbuff[glb->pos->x] = glb->move->perp_wall_dist;
		glb->pos->x++;
	}
//	img_sprite(glb);
	return (1);
}
