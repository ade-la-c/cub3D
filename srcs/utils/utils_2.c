/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:18:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/18 20:09:57 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void					free_filepaths(t_file *file)
{
	free(file->no.path);
	free(file->so.path);
	free(file->we.path);
	free(file->ea.path);
	free(file->s.path);
	return ;
}

void					exit_error(char *error)
{
	ft_putstr(error);
	ft_putchar('\n');
	exit(0);
	return;
}
