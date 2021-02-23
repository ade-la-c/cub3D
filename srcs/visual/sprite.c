/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:25:42 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/22 16:23:33 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void				init_sprite(t_spr *spr, t_map *map, t_glb *glb, int i)
{
	spr->spr.x = map->spr_x[i] - map->pos.x;
	spr->spr.y = map->spr_y[i] - map->pos.y;
	spr->invdir = 1.0 / (glb->pos->plane_cam.x * glb->pos->dir.y -
		glb->pos->dir.x * glb->pos->plane_cam.y);
	spr->transform.x = spr->invdir * (glb->pos->dir.y * spr->spr.x -
		glb->pos->dir.x * spr->spr.y);
	spr->transform.y = spr->invdir * (-glb->pos->plane_cam.y * spr->spr.x +
		glb->pos->plane_cam.x * spr->spr.y);
	spr->screenx = (int)((glb->file->r.x / 2) * (1 + spr->transform.x /
		spr->transform.y));
	spr->height = abs((int)(glb->file->r.y / spr->transform.y));
	spr->dwstart.y = -spr->height / 2 + glb->file->r.y / 2/* + spr->vmovesc*/;
	if (spr->dwstart.y < 0)
		spr->dwstart.y = 0;
	spr->dwend.y = spr->height / 2 + glb->file->r.y / 2/* + spr->vmovesc*/;
	if (spr->dwend.y >= spr->height)
		spr->dwend.y = glb->file->r.y - 1;
	spr->width = abs((int)(glb->file->r.y / spr->transform.y));
	spr->dwstart.x = -spr->width / 2 + spr->screenx;
	if (spr->dwstart.x < 0)
		spr->dwstart.x = 0;
	spr->dwend.x = spr->width / 2 + spr->screenx;
	if (spr->dwend.x >= glb->file->r.x)
		spr->dwend.x = glb->file->r.x - 1;
}

static void				sort_sprite(t_spr *spr, t_map *map)
{
	int					i;
	int					j;

	i = 0;
	while (i < spr->numsprite - 1)
	{
		spr->sp_order = ft_calloc(sizeof(int), spr->numsprite);
		spr->sp_dist = ft_calloc(sizeof(double), spr->numsprite);
		spr->sp_order[i] = i;
		spr->sp_dist[i] = ((map->pos.x - map->spr_x[i]) *
			(map->pos.x - map->spr_x[i]) +
			(map->pos.y - map->spr_y[i]) *
			(map->pos.y - map->spr_y[i]));
		j = i + 1;
		while (j < spr->numsprite)
		{
			if (((map->pos.x - map->spr_x[j]) *
			(map->pos.x - map->spr_x[j]) +
			(map->pos.y - map->spr_y[j]) *
			(map->pos.y - map->spr_y[j])) > (int)spr->sp_dist)
			{
				tmp(map, i, j, 'x');
				tmp(map, i, j, 'y');
			}
			j++;
		}
		i++;
	}
	return ;
}

void					img_sprite(t_glb *glb)
{
	int					i;
	
	i = 0;
	sort_sprite(glb->spr, glb->map);
	while (i < glb->spr->numsprite)
	{
		ft_init_sprite(glb->spr, glb->map, glb, i);
		glb->spr->stripe = glb->spr->dwstart.x;
		while (glb->spr->stripe < glb->spr->dwend.x)
		{
			ft_draw_stripe(glb->spr, glb->file, glb->pos);
			glb->spr->stripe++;
		}
		i++;
	}
	return ;
}
