/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:35:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/16 20:27:00 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void					start_pos(t_glb *glb)
{
	init_struct(glb->move, glb->map);
	condition_ray(glb->move, glb->map);
	move_square(glb->move, glb->map);
	pxl_to_fill(glb->move, glb->file, glb->map);
	//color_assign(glb->map, glb->move, glb->file);
	
	return ;
}

int							algo_raycasting(t_glb *glb)
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
		start_pos(glb);
		glb->spr->zbuff[glb->pos->x] = glb->move->perp_wall_dist;
		glb->pos->x++;
	}
	img_sprite(glb);
	return (1);
}
