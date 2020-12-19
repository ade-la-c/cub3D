/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:26:40 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/19 17:48:53 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				t_rgb_init(t_rgb *rgb)
{
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
	return ;
}

void				t_vec_init(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	return ;
}
/*
void				exit_error(int errno)
{
	write(STDERR_FILENO, "error\n", 6);
	exit(-1);
}
*/