/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:30:27 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/03 16:56:57 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void					parse_vec(char *line, t_vec *vec, int *parsed, int i)
{
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		exit_error("FILE : format error in resolution parameter");
	vec->x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	vec->y = ft_atoi(&line[i]);
	if (vec->x <= 0 || vec->y <= 0)
		exit_error("FILE : resolution can't be zero");
	parsed++;
	return ;
}

void					parse_path(char *line, char **path, int *parsed, int i)
{
	char				*str;
	int					j;

	j = -1;
	str = ft_strtrim(&line[i], " ");
	while (str[i + ++j])
	{
		if (ft_isspace(str[i + j]))
			exit_error("FILE : format error in path parameters");
	}
	if (j < 1)
		exit_error("FILE : path parameter is incomplete");
	*path = str;
	parsed++;
	return ;
}

static char				**split_rgb(char *line, int i)
{
	int				n;
	int				j;
	char			**strs;

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

void					parse_rgb(char *line, t_rgb *rgb, int *parsed, int i)
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
		if (!(ft_atoi(trim[j]) >= 0 && ft_atoi(trim[j]) <= 255
		&& ft_strlen(trim[j]) < 4))
			exit_error("FILE : format error in rgb parameters");
	}
	while (j-- && strs[j])
		free(strs[j]);
	free(strs);
	rgb->r = (char)ft_atoi(trim[0]);
	rgb->g = (char)ft_atoi(trim[1]);
	rgb->b = (char)ft_atoi(trim[2]);
	parsed++;
	return ;
}

/*
**	->tous les paths sont malloqués
*/

void	imprimer_file(t_file *file)
{
	printf("R %d %d\n", file->r.x, file->r.y);
	printf("NO %s\n", file->no);
	printf("SO %s\n", file->so);
	printf("WE %s\n", file->we);
	printf("EA %s\n", file->ea);
	printf("S %s\n", file->s);
	printf("F %d, %d, %d\n", file->f.r, file->f.g, file->f.b);
	printf("C %d, %d, %d\n", file->c.r, file->c.g, file->c.b);
	printf("\n");
	return ;
}
