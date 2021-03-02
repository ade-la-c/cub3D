/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:56:24 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/02 19:30:19 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
**	dir_to_vec détermine la position du joueur et son orientation dans la map
*/

void					dir_to_vec(int i, t_pos *pos)
{
	pos->dir.x = 0;
	pos->dir.y = 0;
	pos->plane_cam.x = 0;
	pos->plane_cam.y = 0;
	if (i == 'N')
	{
		pos->dir.x = -1.0;
		pos->plane_cam.y = 0.66;
	}
	else if (i == 'S')
	{
		pos->dir.x = 1.0;
		pos->plane_cam.y = -0.66;
	}
	else if (i == 'E')
	{
		pos->dir.y = 1.0;
		pos->plane_cam.x = 0.66;
	}
	else if (i == 'W')
	{
		pos->dir.y = -1.0;
		pos->plane_cam.x = -0.66;
	}
	return ;
}

/*
**	verif_holes & verif_holes_2 check qu'il y a pas des trous sans murs
**	dans la map
*/

static void				verif_holes_2(t_map *map, int i, int j)
{
	if (map->map[i][j] == 3 || map->map[i][j] == 2)
	{
		if (!(j < map->width - 1) || j == 0)
			exit_error("holes in the map");
		if (!(i < map->height - 1) || i == 0)
			exit_error("holes in the map");
		if (map->map[i][j - 1] == -1)
			exit_error("holes in the map");
		if (map->map[i][j + 1] == -1)
			exit_error("holes in the map");
		if (map->map[i + 1][j] == -1)
			exit_error("holes in the map");
		if (map->map[i - 1][j] == -1)
			exit_error("holes in the map");
	}
	return ;
}

static void				verif_holes(t_map *map, int height, int width)
{
	int					i;
	int					j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			verif_holes_2(map, i, j);
			j++;
		}
		i++;
	}
}

/*
**	verif_char s'occupe de vérifier qu'il y a pas de char pas autorisés
*/

static void				verif_char(t_map *map, int height, int width)
{
	int					i;
	int					j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map->map[i][j] > 3 || map->map[i][j] < -1)
				exit_error("FILE : wrong map entry");
			j++;
		}
		i++;
	}
	return ;
}

void					verif_map(t_map *map)
{
	verif_char(map, map->height, map->width);
	verif_holes(map, map->height, map->width);
	return ;
}
