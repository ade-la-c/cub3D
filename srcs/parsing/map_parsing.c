/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:33:10 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/23 20:52:07 by ade-la-c         ###   ########.fr       */
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
	map->height = 0;//printf("[%s]\n", tmp->content);
	if (!tmp)
		exit_error("FILE : map is missing");
	while (tmp->content && tmp->next)
	{
		if (((char *)tmp->content)[0] == ' ')
			map_valid_char(tmp->content);
		map->height++;
		map->iter.x = ft_strlen(tmp->content);
		if (map->iter.x > map->width)
			map->width = map->iter.x;
		tmp = tmp->next;
		// if (!ft_strlen(tmp->content))
		// 	break ;
	}
	map->iter.x = 0;
	return (map);
}

/*
**	map_parsing s'occupe de malloc toute la map dans map->map
*/

t_map					*map_parsing(t_list *lst, t_glb *glb)
{
	while (lst && map_valid_char((char *)lst->content) != 1)
	{
		if (!map_valid_char((char *)lst->content))
			exit_error("FILE : a line is wrong");
		lst = lst->next;
	}
	glb->map = get_map_hw(glb->map, lst);
	glb->map->map = (int **)malloc(sizeof(int *) * glb->map->height);
	if (!glb->map->map)
		exit_error("malloc : crash");
	while (glb->map->iter.x < glb->map->height)
	{
		glb->map->map[glb->map->iter.x] = (int *)malloc(sizeof(int) *
		glb->map->width);
		if (!glb->map->map[glb->map->iter.x])
			exit_error("malloc : crash");
		ft_memset(glb->map->map[glb->map->iter.x], -1,
		glb->map->width * sizeof(int));
		glb->map->iter.x++;
	}
	glb->map = map_iter(glb->map, lst, glb->pos);
	if (glb->map->position != 1)
		exit_error("FILE : too many / too few positions in the map");
	verif_map(glb->map);
	return (glb->map);
}

/*
**	->	map->map entièrement malloquée	<-
*/
