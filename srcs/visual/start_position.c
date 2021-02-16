/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:34:31 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/16 20:18:41 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
** Initie delta_dist, hit et position
*/

void						init_struct(t_move *move, t_map *map)
{
	move->map.x = (int)map->pos.x;
	move->map.y = (int)map->pos.y;
	if (move->dir.y == 0)
		move->d_dist.x = 0;
	else
	{
		if (move->dir.x == 0)
			move->d_dist.x = 1;
		else
			move->d_dist.x = fabs(1 / move->dir.x);
	}
	if (move->dir.x == 0)
		move->d_dist.y = 0;
	else
	{
		if (move->dir.y == 0)
			move->d_dist.y = 1;
		else
			move->d_dist.y = fabs(1 / move->dir.y);
	}
	move->hit = 0;
	return ;
}

void						condition_ray(t_move *move, t_map *map)
{
	if (move->dir.x < 0)
	{
		move->step.x = -1;
		move->side_dist.x = (map->pos.x - move->map.x) * move->d_dist.x;
	}
	else
	{
		move->step.x = 1;
		move->side_dist.x = (move->map.x + 1.0 - map->pos.x) *
			move->d_dist.x;
	}
	if (move->dir.y < 0)
	{
		move->step.y = -1;
		move->side_dist.y = (map->pos.y - move->map.y) * move->d_dist.y;
	}
	else
	{
		move->step.y = 1;
		move->side_dist.y = (move->map.y + 1.0 - map->pos.y) *
			move->d_dist.y;
	}
	return ;
}

void						move_square(t_move *move, t_map *map)
{
	move->side = 0;
	while (move->hit == 0)
	{
		if (move->side_dist.x < move->side_dist.y)
		{
			move->side_dist.x += move->d_dist.x;
			move->map.x += move->step.x;
			move->side = 0;
		}
		else
		{
			move->side_dist.y += move->d_dist.y;
			move->map.y += move->step.y;
			move->side = 1;
		}
		if (map->map[(int)move->map.x][(int)move->map.y] == 1)
			move->hit = 1;
	}
	return ;
}

void						pxl_to_fill(t_move *move, t_file *file, t_map *map)
{
	if (move->side == 0)
		move->perp_wall_dist = (move->map.x - map->pos.x +
			(1 - move->step.x) / 2) / move->dir.x;
	else
		move->perp_wall_dist = (move->map.y - map->pos.y +
			(1 - move->step.y) / 2) / move->dir.y;
	move->line_h = (int)(file->r.y / move->perp_wall_dist);
	move->draw_start = -move->line_h / 2 + file->r.y / 2;
	if (move->draw_start < 0)
		move->draw_start = 0;
	move->draw_end = move->line_h / 2 + file->r.y / 2;
	if (move->draw_end >= file->r.y)
		move->draw_end = file->r.y - 1;
	return ;
}

// void		color_assign(t_map *map, t_move *move, t_file *file)
// {
// 	if (map->map[(int)move->map.x][(int)move->map.y] == 1)
// 	{
// 		map->wall_color.r = 0x00800000;
// 		map->wall_color.g = 0;
// 		map->wall_color.b = B;
// 	}
// 	else if (map->map[(int)move->map.x][(int)move->map.y] == 2)
// 	{
// 		map->wall_color.r = 0;
// 		map->wall_color.g = G;
// 		map->wall_color.b = 0;
// 	}
// 	map->colorc = data->b_sky + data->g_sky * 256 + data->r_sky * 65536;
// 	map->colorf = data->b_ground + data->g_ground * 256 + data->r_ground * 65536;
// }

/*
**	color assign ça a géchan
*/