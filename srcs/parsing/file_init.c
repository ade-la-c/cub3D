/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:08:56 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/11 16:47:40 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
**	lsthub sert de hub pour le parsing des paramètres du .cub
*/

static void			lsthub(t_list *lst, t_file *file)
{
	char			*tmp;

	tmp = (char *)lst->content;
	if (!ft_strncmp(tmp, "R ", 2))
		return (parse_res(tmp, &file->r, file, 1));
	else if (!ft_strncmp(tmp, "NO ", 3))
		return (parse_path(tmp, &file->no, file, 2));
	else if (!ft_strncmp(tmp, "SO ", 3))
		return (parse_path(tmp, &file->so, file, 2));
	else if (!ft_strncmp(tmp, "WE ", 3))
		return (parse_path(tmp, &file->we, file, 2));
	else if (!ft_strncmp(tmp, "EA ", 3))
		return (parse_path(tmp, &file->ea, file, 2));
	else if (!ft_strncmp(tmp, "S ", 2))
		return (parse_path(tmp, &file->s, file, 1));
	else if (!ft_strncmp(tmp, "F ", 2))
		return (parse_rgb(tmp, &file->f, file, 1));
	else if (!ft_strncmp(tmp, "C ", 2))
		return (parse_rgb(tmp, &file->c, file, 1));
	else if (tmp[0] && file->parsed < 8)
		exit_error("FILE : A line is wrong");
	return ;
}

static void			t_file_init(t_file *file)
{
	t_coord_init(&file->r);
	file->no = NULL;
	file->so = NULL;
	file->we = NULL;
	file->ea = NULL;
	file->s = NULL;
	t_rgb_init(&file->f);
	t_rgb_init(&file->c);
	file->parsed = 0;
}

/*
**	parse_lst envoie la liste a lsthub ligne par ligne
*/

static void			parse_lst(t_list **lst)
{
	t_file			file;
	t_list			*a;
	t_map			map;
	t_pos			pos;

	a = *lst;
	t_file_init(&file);
	while (a && file.parsed < 8)
	{
		lsthub(a, &file);
		a = a->next;
	}
	if (file.parsed == 8)
	{
		map_parsing(a, &file, &map, &pos);
	} //imprimer_file(&file);
	return ;
	}

/*
**	file_to_lst convertit le fichier .cub en t_list afin de parser les données
*/

void				file_to_lst(char *filepath)
{
	t_list			**lst;
	t_list			*el;
	char			*line;
	int				fd;

	
	if (!((lst = malloc(sizeof(t_list *)))))
		return ;
	*lst = NULL;
	if (!(fd = open(filepath, O_RDONLY)))
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		el = ft_lstnew(line);
		ft_lstadd_back(lst, el);
	}
	el = ft_lstnew(line);
	ft_lstadd_back(lst, el);
	close(fd);
	parse_lst(lst);
	return ;
}
