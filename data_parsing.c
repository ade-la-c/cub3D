/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:30:27 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/20 18:01:58 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				parse_vec(char *line, t_vec *vec, int i)
{
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return ;		//error
	vec->x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	vec->y = ft_atoi(&line[i]);
	return ;
}

void				parse_path(char *line, char **path, int i)
{
	while (line[i] == ' ')
		i++;
	*path = ft_strdup(&line[i]);
	return ;
}

void				parse_rgb(char *line, t_rgb *rgb, int i)
{
	int				checker;

	checker = 0;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return ;		//error
	rgb->r = ft_atoi(&line[i]);
	while (line[i] == ' ' || line[i] == ',')
		if (line[i] == ',')
			checker++;
	if (checker != 1)
		return ;		//error
	checker = 0;
	rgb->g = ft_atoi(&line[i]);
	while (line[i] == ' ' || line[i] == ',')
		if (line[i] == ',')
			checker++;
	if (checker != 1)
		return ;		//error
	rgb->b = ft_atoi(&line[i]);
	return ;
}

/*
	-> Il y a un crash au niveau de ft_lstadd_back, les fonctions
	lst sont justes, la n'est pas le probleme
	-> les fonctions above sont encore à tester
*/