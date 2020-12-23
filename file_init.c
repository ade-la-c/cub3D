/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:08:56 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/23 17:30:01 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			lsthub(t_list *lst, t_file *file)
{
	char			*tmp;

	tmp = (char *)lst->content;
	if (!ft_strncmp(tmp, "R ", 2))
		parse_vec(tmp, &file->r, 1);
	else if (!ft_strncmp(tmp, "NO ", 3))
		parse_path(tmp, &file->no, 2);
	else if (!ft_strncmp(tmp, "SO ", 3))
		parse_path(tmp, &file->so, 2);
	else if (!ft_strncmp(tmp, "WE ", 3))
		parse_path(tmp, &file->we, 2);
	else if (!ft_strncmp(tmp, "EA ", 3))
		parse_path(tmp, &file->ea, 2);
	else if (!ft_strncmp(tmp, "S ", 2))
		parse_path(tmp, &file->s, 1);
	else if (!ft_strncmp(tmp, "F ", 2))
		parse_rgb(tmp, &file->f, 1);
	else if (!ft_strncmp(tmp, "C ", 2))
		parse_rgb(tmp, &file->c, 1);
	return ;
}

static void			t_file_init(t_file *file)
{
	t_vec_init(&file->r);
	file->no = NULL;
	file->so = NULL;
	file->we = NULL;
	file->ea = NULL;
	file->s = NULL;
	t_rgb_init(&file->f);
	t_rgb_init(&file->c);
}

void				parse_lst(t_list **lst)
{
	t_file			file;
	t_list			*a;

	a = *lst;
	t_file_init(&file);
	while (a)
	{
		lsthub(a, &file);
		a = a->next;
	}
	imprimer_file(&file);
	return ;
}

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

int					main(void)
{
	char			*filepath = "./assets/file.cub";

	file_to_lst(filepath);
	return (0);
}
