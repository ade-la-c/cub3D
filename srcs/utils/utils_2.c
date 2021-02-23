/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:18:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/23 20:49:14 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// void					free_filepaths(t_file *file)
// {
// 	free(file->no.path);
// 	free(file->so.path);
// 	free(file->we.path);
// 	free(file->ea.path);
// 	free(file->s.path);
// 	return ;
// }

void					exit_error(char *error)
{
	ft_putstr(error);
	ft_putchar('\n');
	exit(0);
	return;
}

int						map_valid_char(char *str)
{
	int					i;

	i = 0;
	if (!str || !str[i])
		return (-1);
	while (str && str[i] && ft_isspace(str[i]))
		i++;
	if (str && str[i])
		return (1);
	else
		exit_error("FILE : a line is wrong (whitespaces)");
	return (0);
}
