/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:33:10 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/12 18:52:30 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
**	pos_assign s'occupe de déterminer la position de la caméra dans la map
*/

static void				pos_assign(int i, t_map *map, t_pos *pos)
{
	map->map[map->iter.y][map->iter.x] = i;
	map->pos.x = map->iter.y + 0.5;
	map->pos.y = map->iter.x + 0.5;
	dir_to_vec(i, pos);
	map->map[map->iter.y][map->iter.x] = 3;
	map->position++;
	return ;
}

/*
**	map_fill remplit case par case le tableau map->map
*/

static t_map			*map_fill(t_list *lst, t_map *map, t_pos *pos)
{
	int					i;

	i = 0;
	while (((char *)lst->content)[map->iter.x])
	{
		map->map[map->iter.y][map->iter.x] = 4;
		if (((char *)lst->content)[map->iter.x] == ' ')
			map->map[map->iter.y][map->iter.x] = -1;
		else if (((char *)lst->content)[map->iter.x] == '0')
			map->map[map->iter.y][map->iter.x] = 3;
		else if (((char *)lst->content)[map->iter.x] == '1')
			map->map[map->iter.y][map->iter.x] = 1;
		else if (((char *)lst->content)[map->iter.x] == '2')
			map->map[map->iter.y][map->iter.x] = 2;
		else if (((char *)lst->content)[map->iter.x] == 'N' ||
				((char *)lst->content)[map->iter.x] == 'S' ||
				((char *)lst->content)[map->iter.x] == 'E' ||
				((char *)lst->content)[map->iter.x] == 'W')
			pos_assign(((char *)lst->content)[map->iter.x], map, pos);
		map->iter.x++;
		i++;
	}
	if (i < map->height)
		exit_error("FILE : too many maps");
	return (map);
}

/*
**	map_iter sert à itérer dans la map dans la coordonnée x
*/

static t_map			*map_iter(t_map *map, t_list *lst, t_pos *pos)
{
	int					height;

	height = map->height;
	map->iter.x = 0;
	map->iter.y = 0;
	map->position = 0;
	while (lst && lst->content && height > 0)
	{
		map = map_fill(lst, map, pos);
		lst = lst->next;
		map->iter.x = 0;
		height--;
		map->iter.y++;
	}
	return (map);
}

/*
**	get_map_hw sert a prendre les dimensions de la map pour
**	connaître la taille a malloc
*/

static t_map			*get_map_hw(t_map *map, t_list *lst)
{
	t_list				*tmp;

	tmp = lst;
	map->height = 0;
	while (tmp->content && tmp->next)
	{
		map->height++;
		map->iter.x = ft_strlen(tmp->content);
		if (map->iter.x > map->width)
			map->width = map->iter.x;
		tmp = tmp->next;
	}
	map->iter.x = 0;
	return (map);
}

/*
**	map_parsing s'occupe de malloc toute la map dans map->map
*/

t_glb					map_parsing(t_list *lst, t_file *file, t_map *map,
									t_pos *pos)
{
	file->parsed = 9;
	while (lst && !((char*)lst->content)[0])
		lst = lst->next;
	map = get_map_hw(map, lst);
	map->map = (int **)malloc(sizeof(int *) * map->height);
	if (!map->map)
		exit_error("Crash malloc"));
	while (map->iter.x < map->height)
	{
		map->map[map->iter.x] = (int *)malloc(sizeof(int) * map->width);
		if (!map->map[map->iter.x])
			exit_error("Crash malloc"));
		ft_memset(map->map[map->iter.x], -1, map->width * sizeof(int));
		map->iter.x++;
	}
	map = map_iter(map, lst, pos);
	if (map->position != 1)
		exit_error("FILE : too many / too few positions in the map");
	verif_map(map);
	return ;
}

/*
**	->	map->map entièrement malloquée	<-
*/
