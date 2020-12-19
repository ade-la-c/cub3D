/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:30:27 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/19 18:07:48 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				parse_r(t_file *file, char *line)
{
	int				i;

	i = 0;
	if (line[i] != 'R')
		return ;
	i++;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return ;
	file->r.x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	file->r.y = ft_atoi(&line[i]);
	printf("x = %d\ny = %d\n", file->r.x, file->r.y);
	return ;
}
