/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:18:03 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/15 17:16:52 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void					free_file(t_file *file, char *str)
{
	free(file->no);
	free(file->so);
	free(file->we);
	free(file->ea);
	exit_error(str);
	return ;
}

void					exit_error(char *error)
{
	ft_putstr(error);
	ft_putchar('\n');
	exit(0);
	return;
}
