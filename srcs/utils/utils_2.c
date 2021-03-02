/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:18:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/02 19:56:57 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int						isposition(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void					res_fix(t_mlibx *mlibx, t_file *file)
{
	int					x;
	int					y;

	mlx_get_screen_size(mlibx->mlx_ptr, &x, &y);
	if (file->r.x > x)
		file->r.x = x;
	if (file->r.y > y)
		file->r.y = y;
}

void					exit_error(char *error)
{
	ft_putstr(error);
	ft_putchar('\n');
	system("leaks Cub3D");
	exit(0);
}

void					final_free(t_glb *glb)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%p\n", &glb->map->map);
	free(glb);
	// free(glb->map->spr_x);
	// free(glb->map->spr_y);
	// free(glb->pos->color2);
}