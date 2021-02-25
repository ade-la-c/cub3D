/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:33 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/25 21:11:19 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	struct_init mallocs all the structures we're going to use in cub3D
*/

static t_glb				*struct_init(void)
{
	t_glb					*glb;

	glb = calloc_struct(sizeof(t_glb));
	glb->file = calloc_struct(sizeof(t_file));
	glb->map = calloc_struct(sizeof(t_map));
	glb->mlibx = calloc_struct(sizeof(t_mlibx));
	glb->pos = calloc_struct(sizeof(t_pos));
	glb->move = calloc_struct(sizeof(t_move));
	glb->spr = calloc_struct(sizeof(t_spr));
	return (glb);
}

int							main(int ac, char **av)
{
	t_glb					*glb;

	glb = struct_init();
	glb->mlibx->mlx_ptr = mlx_init();
	if (!(ac == 2 || ac == 3))
		exit_error("too many / too few main arguments");
	glb = parsing((char *)av[1], glb);
	minilibx_get_image(glb->mlibx, glb->file);
	if (ac == 2 || (ac == 3 && !ft_strncmp((char *)av[2], "--save", 7)))
	{
		hook_loop(ac, glb);
	}
	if (ac == 3 && ft_strncmp((char *)av[2], "--save", 7))
		exit_error("argc[3] must be --save");
	return (0);
}
