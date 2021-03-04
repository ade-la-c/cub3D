/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:30:27 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/04 14:25:25 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void					parse_res(char *line, t_coord *res, t_file *file, int i)
{
	if (res->x != 0 || res->y != 0)
		exit_error("FILE : resolution has been entered twice");
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		exit_error("FILE : format error in resolution parameter");
	res->x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	res->y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i])
		if (line[i++] != ' ')
			exit_error("FILE : format error in resolution parameter");
	if (res->x <= 0 || res->y <= 0 || res->x >= 2147483646
	|| res->y >= 2147483646)
		exit_error("FILE : resolution value is not valid");
	file->parsed++;
	return ;
}

void					parse_path(char *line, char **path, t_file *file, int i)
{
	char				*str;
	int					j;

	j = -1;
	if (*path != NULL)
		exit_error("FILE : path parameter has been entered twice");
	str = ft_strtrim(&line[i], " ");
	if (!str)
		exit_error("ft_strtrim : crash");
	while (str[i + ++j])
		if (ft_isspace(str[i + j]))
			exit_error("FILE : format error in path parameters");
	if (j < 1)
		exit_error("FILE : path parameter is incomplete");
	*path = str;
	file->parsed++;
	return ;
}

static char				**split_rgb(char *line, int i)
{
	int					n;
	int					j;
	char				**strs;

	n = 0;
	j = 0;
	strs = ft_split(&line[i], ',');
	if (!strs)
		exit_error("ft_split : crash");
	while (line[i++])
		if (line[i] == ',')
			n++;
	if (n != 2)
		exit_error("FILE : format error in rgb parameters");
	while (strs[j] != NULL)
		j++;
	if (j != 3)
		exit_error("FILE : format error in rgb parameters");
	return (strs);
}

static void				free_rgb(char **strs, char **trim)
{
	int					i;

	i = -1;
	while (++i < 3)
		free(strs[i]);
	free(strs);
	while (i-- > 0)
		free(trim[i]);
	return ;
}

void					parse_rgb(char *line, t_rgb *rgb, t_file *file, int i)
{
	char				**strs;
	char				*trim[3];
	int					j;

	j = 0;
	if (rgb->check != 0)
		exit_error("FILE : parameter has been entered twice or more");
	rgb->check++;
	strs = split_rgb(line, i);
	j = -1;
	while (strs[++j] != NULL)
	{
		trim[j] = ft_strtrim(strs[j], " ");
		if (!trim[j])
			exit_error("ft_strtrim : crash");
		if (!(ft_atoi(trim[j]) >= 0 && ft_atoi(trim[j]) <= 255
		&& ft_strlen(trim[j]) < 4))
			exit_error("FILE : format error in rgb parameters");
	}
	rgb->r = (char)ft_atoi(trim[0]);
	rgb->g = (char)ft_atoi(trim[1]);
	rgb->b = (char)ft_atoi(trim[2]);
	free_rgb(strs, trim);
	file->parsed++;
	return ;
}
