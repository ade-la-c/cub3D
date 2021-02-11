/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:33 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/11 21:22:22 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	file_to_lst(av[1]);
	if (!(ac == 2 || ac == 3))
		exit_error("too many / too few main arguments");
	file_to_lst((char *)av[1]);
	if (ac == 2 || (ac == 3 && !ft_strncmp((char *)av[2], "--save", 7)))
	{
		hook_loop();
	}
//	system("leaks Cub3D");
	return (0);
}
