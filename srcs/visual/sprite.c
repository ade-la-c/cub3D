/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:25:42 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/16 20:28:58 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void						img_sprite(t_glb *glb)
{
	int						i;
	
	i = 0;
	glb->spr = ft_calloc_2(sizeof(t_spr));
	ft_sort_sprite(glb->spr, glb->map);
	while (i < glb->map->numsprite)
	{
		ft_init_sprite(glb->spr, glb->map, glb, i);
		glb->spr->stripe = glb->spr->dwstart.x;
		while (glb->spr->stripe < glb->spr->dwend.x)
		{
			ft_draw_stripe(glb->spr, glb->file, glb->pos);
			glb->spr->stripe++;
		}
		i++;
	}
	return ;
}

