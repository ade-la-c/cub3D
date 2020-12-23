/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:30:27 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/23 18:35:03 by ade-la-c         ###   ########.fr       */
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
	while (ft_isdigit(line[i]) != 0)
		i++;
	while ((line[i] == ' ' || line[i] == ','))
	{
		if (line[i] == ',')
			checker++;
		i++;
	}
	if (checker != 1)
		return ;		//error
	checker = 0;
	rgb->g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) != 0)
		i++;
	while (line[i] == ' ' || line[i] == ',')
	{
		if (line[i] == ',')
			checker++;
		i++;
	}
	if (checker != 1)
		return ;		//error
	rgb->b = ft_atoi(&line[i]);
	return ;
}

/*
	-> les fonctions du parsing fonctionnent correctement, je dois utiliser
	le systeme de bitflags pour identifier les doublons (des parametres)
	afin d'envoyer une erreur
	-> les commentaires "//erreur" dans ce fichier correspondent a des 
	returns qui doivent etre remplacés par une fonction type "exit_error"
	->parse_rgb reste a normer
*/
/*
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
*/