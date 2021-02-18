/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:08:56 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/18 20:29:22 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
**	lsthub sert de hub pour le parsing des paramètres du .cub
*/

static void					lsthub(t_list *lst, t_file *file)
{
	char					*tmp;

	tmp = (char *)lst->content;
	if (!ft_strncmp(tmp, "R ", 2))
		return (parse_res(tmp, &file->r, file, 1));
	else if (!ft_strncmp(tmp, "NO ", 3))
		return (parse_path(tmp, &file->no.path, file, 2));
	else if (!ft_strncmp(tmp, "SO ", 3))
		return (parse_path(tmp, &file->so.path, file, 2));
	else if (!ft_strncmp(tmp, "WE ", 3))
		return (parse_path(tmp, &file->we.path, file, 2));
	else if (!ft_strncmp(tmp, "EA ", 3))
		return (parse_path(tmp, &file->ea.path, file, 2));
	else if (!ft_strncmp(tmp, "S ", 2))
		return (parse_path(tmp, &file->s.path, file, 1));
	else if (!ft_strncmp(tmp, "F ", 2))
		return (parse_rgb(tmp, &file->f, file, 1));
	else if (!ft_strncmp(tmp, "C ", 2))
		return (parse_rgb(tmp, &file->c, file, 1));
	else if (tmp[0] && file->parsed < 8)
		exit_error("FILE : A line is wrong");
	return ;
}

static void					t_file_init(t_file *file)
{
	t_coord_init(&file->r);
	t_rgb_init(file->f);
	t_rgb_init(file->c);
	file->parsed = 0;
	return ;
}

/*
**	param_parsing envoie la liste a lsthub ligne par ligne
*/

static t_file				*param_parsing(t_list **lst, t_file *file)
{
	t_list					*a;

	a = *lst;
	t_file_init(file);
	while (a && file->parsed < 8)
	{
		lsthub(a, file);
		a = a->next;
	}
	file->lst = a;
	//imprimer_file(&file);
	return (file);
}

/*
**	file_to_lst convertit le fichier .cub en t_list
*/

static t_list				**file_to_lst(char *filepath)
{
	t_list					**lst;
	t_list					*el;
	char					*line;
	int						fd;

	lst = malloc(sizeof(t_list *));
	if (!lst)
		exit_error("malloc : crash");
	*lst = NULL;
	if (!(fd = open(filepath, O_RDONLY)))
		exit_error("open : crash");
	while (get_next_line(fd, &line) > 0)
	{
		el = ft_lstnew(line);
		ft_lstadd_back(lst, el);
	}
	el = ft_lstnew(line);
	ft_lstadd_back(lst, el);
	close(fd);
	return (lst);
}

t_glb						*parsing(char *filepath, t_glb *glb)
{
	glb->file = param_parsing(file_to_lst(filepath), glb->file);
	if (glb->file->parsed == 8)
	{
		glb->file->parsed++;
		glb->map = map_parsing(glb->file->lst, glb);
	}
	return (glb);
}
