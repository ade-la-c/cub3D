/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 20:02:53 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/18 20:12:48 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


/*
**	wall X, texture X
*/

static void			wallx_texx(t_move *move, t_pos *pos, t_map *map, t_tex tex)
{
	if (move->side == 0)
		pos->wall.x = map->pos.y + (move->perp_wall_dist * move->dir.y);
	else
		pos->wall.x = map->pos.x + (move->perp_wall_dist * move->dir.x);
	pos->wall.x -= floor(pos->wall.x);
	pos->tex.x = (int)(pos->wall.x * (double)tex.width);
	if (move->side == 0 && move->dir.x > 0)
		pos->tex.x = tex.width - pos->tex.x - 1;
	if (move->side == 1 && move->dir.y < 0)
		pos->tex.x = tex.width - pos->tex.x - 1;
	return ;
}

/*
**	Wall texture also Wall Y, texture Y
*/

void				texture(t_pos *pos, t_move *move, t_file *file, t_glb *glb)
{
	t_tex			tex;

	if (move->side == 1 && move->dir.y < 0)
		tex = file->no;
	if (move->side == 1 && move->dir.y > 0)
		tex = file->so;
	if (move->side == 0 && move->dir.x < 0)
		tex = file->we;
	if (move->side == 0 && move->dir.x > 0)
		tex = file->ea;
	wallx_texx(move, pos, glb->map, tex);
	pos->stept = (double)tex.height / (double)move->line_h;
	pos->texpos = (move->draw_start - file->r.y / 2 + move->line_h / 2)
		* pos->stept;
	pos->y = move->draw_start;
	pos->tex.y = (int)pos->texpos & (tex.height - 1);
	while (pos->y < move->draw_end)
	{
		pos->color = tex.addr[file->ea.width *
		(int)pos->tex.y + (int)pos->tex.x];
		minilibx_pxl_put(glb->mlibx, pos->x, pos->y, pos->color);
		pos->tex.y += pos->stept;
		pos->y++;
	}
	return ;
}
