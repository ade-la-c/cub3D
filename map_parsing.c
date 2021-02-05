/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:33:10 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/05 18:53:22 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static t_map			*map_fill(t_list *lst, t_map *map, t_pos *pos)
// {
	
// }

static t_map			*map_iter(t_map *map, t_list *lst, t_pos *pos)
{
	int					height;

	height = map->height;
	map->iter.x = 0;
	map->iter.y = 0;
	map->pos = 0;
	while(lst && lst->content && map->height > 0)
	{pos->x = 0;
		//map = map_fill(lst, &map, &pos);
		lst = lst->next;
		map->iter.x = 0;
		height--;
		map->iter.y++;
	}
	return (map);
}

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

void					map_parsing(t_list *lst, t_file *file, t_map *map,
									t_pos *pos)
{
	file->parsed = 9;
	map = get_map_hw(map, lst);
	map->map = (int**)malloc(sizeof(int*) * map->height);
	if (!map->map)
		return ;
	while (map->iter.x < map->height)
	{
		map->map[map->iter.x] = (int*) malloc(sizeof(int) * map->width);
		if (!map->map[map->iter.x])
			return ;
		ft_memset(map->map, -1, map->width * sizeof(int));
		map->iter.x++;
	}
	map = map_iter(map, lst, pos);
	if (map->pos != 1)
		exit_error("oui"); //error
	return ;
}
