/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:25:42 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/03 10:35:33 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void				malloc_sprite(t_map *map)
{
	map->spr_x = ft_calloc(sizeof(int*), (map->numsprite + 1));printf("spr_x %p\n", map->spr_x);
	if (!map->spr_x)
		exit_error("calloc : crash");
	map->spr_y = ft_calloc(sizeof(int*), (map->numsprite + 1));printf("spr_y %p\n", map->spr_y);
	if (!map->spr_y)
		exit_error("calloc : crash");
	map->numsprite = 0;
	return ;
}

static void			draw_stripe(t_glb *glb, t_spr *spr, t_file *file)
{
	spr->tex.x = (int)(spr->stripe - (-spr->width / 2 + spr->screenx)) *
		TXW / spr->width;
	if (spr->transform.y > 0 && spr->stripe > 0 && spr->stripe <
		file->r.x && spr->transform.y < spr->zbuff[spr->stripe])
	{
		spr->y = spr->dwstart.y;
		while (spr->y < spr->dwend.y)
		{
			spr->d = spr->y * 256 - file->r.y * 128 +
				spr->height * 128;
			spr->tex.y = ((spr->d * file->s.height) / spr->height) / 256;
			glb->pos->color = file->s.addr[file->s.width * spr->tex.y +
				spr->tex.x];
			if (glb->pos->color)
				minilibx_pxl_put(glb->mlibx, spr->stripe, spr->y,
								glb->pos->color);
			spr->y++;
		}
	}
}

static void			init_sprite(t_spr *spr, t_map *map, t_glb *glb, int i)
{
	spr->spr.y = map->spr_x[i] - map->pos.y;
	spr->spr.x = map->spr_y[i] - map->pos.x;
	spr->invdir = 1.0 / (glb->pos->plane_cam.x * glb->pos->dir.y -
		glb->pos->dir.x * glb->pos->plane_cam.y);
	spr->transform.x = spr->invdir * (glb->pos->dir.y * spr->spr.x -
		glb->pos->dir.x * spr->spr.y);
	spr->transform.y = spr->invdir * (-glb->pos->plane_cam.y * spr->spr.x +
		glb->pos->plane_cam.x * spr->spr.y);
	spr->screenx = (int)((glb->file->r.x / 2) * (1 + spr->transform.x /
		spr->transform.y));
	spr->height = abs((int)(glb->file->r.y / spr->transform.y));
	spr->dwstart.y = -spr->height / 2 + glb->file->r.y / 2;
	if (spr->dwstart.y < 0)
		spr->dwstart.y = 0;
	spr->dwend.y = spr->height / 2 + glb->file->r.y / 2;
	if (spr->dwend.y >= glb->file->r.y)
		spr->dwend.y = glb->file->r.y - 1;
	spr->width = abs((int)(glb->file->r.y / spr->transform.y));
	spr->dwstart.x = -spr->height / 2 + spr->screenx;
	if (spr->dwstart.x < 0)
		spr->dwstart.x = 0;
	spr->dwend.x = spr->width / 2 + spr->screenx;
	if (spr->dwend.x >= glb->file->r.x)
		spr->dwend.x = glb->file->r.x - 1;
}

/*
** Sorting sprite from far to close
*/

static void			sort_sprite(t_map *map)
{
	int				i;
	double			first;
	double			second;
	double			tmp;

	i = 0;
	while (i < map->numsprite && (i + 1 != map->numsprite))
	{
		first = ((map->pos.y - map->spr_x[i]) * (map->pos.y - map->spr_x[i]) +
			(map->pos.x - map->spr_y[i]) * (map->pos.x - map->spr_y[i]));
		second = ((map->pos.y - map->spr_x[i + 1]) * (map->pos.y -
			map->spr_x[i + 1]) + (map->pos.x - map->spr_y[i + 1]) *
			(map->pos.x - map->spr_y[i + 1]));
		if (first < second)
		{
			tmp = map->spr_x[i];
			map->spr_x[i] = map->spr_x[i + 1];
			map->spr_x[i + 1] = tmp;
			tmp = map->spr_y[i];
			map->spr_y[i] = map->spr_y[i + 1];
			map->spr_y[i + 1] = tmp;
		}
		else
			i++;
	}
}

void				img_sprite(t_glb *glb)
{
	int				i;

	i = 0;
	sort_sprite(glb->map);
	while (i < glb->map->numsprite)
	{
		init_sprite(glb->spr, glb->map, glb, i);
		glb->spr->stripe = glb->spr->dwstart.x;
		while (glb->spr->stripe < glb->spr->dwend.x)
		{
			draw_stripe(glb, glb->spr, glb->file);
			glb->spr->stripe++;
		}
		i++;
	}
}
