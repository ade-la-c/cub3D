/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:33 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/17 17:21:43 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				struct_init(t_glb *glb)
{
	glb = ft_calloc(1, sizeof(t_glb));
	glb->file = ft_calloc(1, sizeof(t_file));
	glb->map = ft_calloc(1, sizeof(t_map));
	glb->mlibx = ft_calloc(1, sizeof(t_mlibx));
	glb->pos = ft_calloc(1, sizeof(t_pos));
	glb->move = ft_calloc(1, sizeof(t_move));
	glb->spr = ft_calloc(1, sizeof(t_spr));
	return ;
}

int					main(int ac, char **av)
{
	t_glb			*glb;

	glb = NULL;
	struct_init(glb);
	if (!(ac == 2 || ac == 3))
		exit_error("too many / too few main arguments");
	glb = parsing((char *)av[1], glb);
	if (ac == 2 || (ac == 3 && !ft_strncmp((char *)av[2], "--save", 7)))
	{
		hook_loop(ac, glb);
	}
	if (ac == 3 && ft_strncmp((char *)av[2], "--save", 7))
		exit_error("argc[3] must be --save");
//	system("leaks Cub3D");
	return (0);
}
