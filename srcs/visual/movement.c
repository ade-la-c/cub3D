/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:17:33 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/19 18:42:49 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void					mv_forward(t_pos *pos, t_map *map)
{
	if (KEYCODE_W)
	{
		if (map->map[(int)(map->pos.x + pos->dir.x * 0.2)][(int)map->pos.y]
			== 3)
			map->pos.x += pos->dir.x * MS;
		if (map->map[(int)map->pos.x][(int)(map->pos.y + pos->dir.y * 0.2)]
			== 3)
			map->pos.y += pos->dir.y * MS;
	}
	return ;
}

void					mv_backward(t_pos *pos, t_map *map)
{
	if (KEYCODE_S)
	{
		if (map->map[(int)(map->pos.x - pos->dir.x * 0.2)][(int)map->pos.y]
			== 3)
			map->pos.x -= pos->dir.x * MS;
		if (map->map[(int)map->pos.x][(int)(map->pos.y - pos->dir.y * 0.2)]
			== 3)
			map->pos.y -= pos->dir.y * MS;
	}
	return ;
}

void					mv_left(t_pos *pos, t_map *map)
{
	double				i;
	double				j;

	i = 0.2 - (0.4 * (pos->dir.y > 0));
	j = 0.2 - (0.4 * (pos->dir.x < 0));
	if (map->map[(int)map->pos.x][(int)map->pos.y] == 3)
		map->pos.y += pos->dir.x * MS;
	if (map->map[(int)(map->pos.x + i)][(int)map->pos.y] == 3)
		map->pos.x -= pos->dir.y * MS;
	return ;
}

void					mv_right(t_pos *pos, t_map *map)
{
	double				i;
	double				j;

	i = 0.2 - (0.4 * (pos->dir.y < 0));
	j = 0.2 - (0.4 * (pos->dir.x > 0));
	if (map->map[(int)(map->pos.x + i)][(int)map->pos.y] == 3)
		map->pos.x += pos->dir.y * MS;
	if (map->map[(int)map->pos.x][(int)(map->pos.y + j)] == 3)
		map->pos.y -= pos->dir.x * MS;
	return ;
}
