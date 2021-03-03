/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:18:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/03 11:56:38 by ade-la-c         ###   ########.fr       */
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
{printf("pointeur %p\n", glb->mlibx->img);
	int					i;

	i = 0;
	free(glb->mlibx);
	free(glb->pos);
	free(glb->spr);
	free(glb->move);
	free(glb->map->spr_x);
	free(glb->map->spr_y);
	while (i < glb->map->height)
	{
		free(glb->map->map[i]);
		i++;
	}
	free(glb->map->map);
	free(glb->map);
	free(glb);
}