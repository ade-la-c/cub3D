/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:33 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/15 18:59:45 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					main(int ac, char **av)
{
	t_glb			*glb;

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
