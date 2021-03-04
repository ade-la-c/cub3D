/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:18:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/04 16:46:02 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

/*
**	exit_error est la fonction qui se charge de fermer le programme chaque fois
**	qu'un problème est rencontré
*/

void					exit_error(char *error)
{
	ft_putstr(error);
	ft_putchar('\n');
	exit(0);
}

/*
**	final_free est appelé à la sortie du programme pour free toutes les
**	allocations faites pendant l'execution du programme
*/

void					final_free(t_glb *glb)
{
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
