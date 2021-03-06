/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:26:40 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/04 16:50:45 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	les fonctions _init se lancent pendant le parsing
*/

void				t_rgb_init(t_rgb rgb)
{
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	rgb.check = 0;
	return ;
}

void				t_vec_init(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	return ;
}

void				t_coord_init(t_coord *coord)
{
	coord->x = 0;
	coord->y = 0;
	return ;
}

int					ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

/*
**	calloc_struct est un calloc modifié pour allouer des structures plus
**	facilement, il est appelé dans main.c
*/

void				*calloc_struct(size_t nmemb)
{
	void			*tab;

	tab = malloc(nmemb);
	if (!tab)
		exit_error("calloc : error");
	ft_bzero(tab, nmemb);
	return (tab);
}
