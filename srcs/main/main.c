/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:33 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/04 16:42:01 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int					verif_file_arg(char *filearg)
{
	if (!ft_strncmp(ft_strchr(filearg, '.'), ".cub", 4))
		return (1);
	return (0);
}

/*
**	struct_init mallocs all the structures we're going to use in cub3D
*/

static t_glb				*struct_init(void)
{
	t_glb					*glb;

	glb = calloc_struct(sizeof(t_glb));
	if (!glb)
		exit_error("calloc : crash");
	glb->file = calloc_struct(sizeof(t_file));
	if (!glb->file)
		exit_error("calloc : crash");
	glb->map = calloc_struct(sizeof(t_map));
	if (!glb->map)
		exit_error("calloc : crash");
	glb->mlibx = calloc_struct(sizeof(t_mlibx));
	if (!glb->mlibx)
		exit_error("calloc : crash");
	glb->pos = calloc_struct(sizeof(t_pos));
	if (!glb->pos)
		exit_error("calloc : crash");
	glb->move = calloc_struct(sizeof(t_move));
	if (!glb->move)
		exit_error("calloc : crash");
	glb->spr = calloc_struct(sizeof(t_spr));
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
	if (!verif_file_arg(av[1]))
		exit_error("file must be .cub");
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
