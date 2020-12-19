/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:30:27 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/19 20:29:39 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				parse_r(t_file *file, char *line)
{
	int				i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return ;		//error
	file->r.x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	file->r.y = ft_atoi(&line[i]);
	return ;
}

void				parse_path(t_file *file, char *line, char *path)
{
	int				i;

	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup(&line[i]);
	return ;
}

void				parse_f(t_file *file, char *line)
{
	int				i;
	int				checker;

	i = 1;
	checker = 0;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return ;		//error
	file->f.r = ft_atoi(&line[i]);
	while (line[i] == ' ' || line[i] == ',')
		if (line[i] == ',')
			checker++;
	if (checker != 1)
		return ;		//error
	checker = 0;
	file->f.g = ft_atoi(&line[i]);
	while (line[i] == ' ' || line[i] == ',')
		if (line[i] == ',')
			checker++;
	if (checker != 1)
		return ;		//error
	file->f.b = ft_atoi(&line[i]);
	return ;
}

/*
	-> Il y a un crash au niveau de ft_lstadd_back, les fonctions
	lst sont justes, la n'est pas le probleme
	-> les fonctions above sont encore à tester
	-> parse_no _so _we _ea (et peut-être _s) sont fusionnables
	dans la meme fonction afin de reduire le data_parsing a un
	seul fichier (a tester)
	|-> parse_path (pour tous les path en (char *) dans t_file)
		prend comme parametre (char *path) je dois entrer l'adresse
		de path

*/