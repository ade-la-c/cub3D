/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:33 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/03 10:38:25 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	struct_init mallocs all the structures we're going to use in cub3D
*/

static t_glb				*struct_init(void)
{
	t_glb					*glb;

	glb = calloc_struct(sizeof(t_glb));printf("glb %p\n", glb);
	if (!glb)
		exit_error("calloc : crash");
	glb->file = calloc_struct(sizeof(t_file));printf("glb->file %p\n", glb->file);
	if (!glb->file)
		exit_error("calloc : crash");
	glb->map = calloc_struct(sizeof(t_map));printf("glb->map %p\n", glb->map);
	if (!glb->map)
		exit_error("calloc : crash");
	glb->mlibx = calloc_struct(sizeof(t_mlibx));printf("glb->mlibx%p\n", glb->mlibx);
	if (!glb->mlibx)
		exit_error("calloc : crash");
	glb->pos = calloc_struct(sizeof(t_pos));printf("glb->pos %p\n", glb->pos);
	if (!glb->pos)
		exit_error("calloc : crash");
	glb->move = calloc_struct(sizeof(t_move));printf("glb->move %p\n", glb->move);
	if (!glb->move)
		exit_error("calloc : crash");
	glb->spr = calloc_struct(sizeof(t_spr));printf("glb->spr %p\n", glb->spr);
	if (!glb->spr)
		exit_error("calloc : crash");
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
