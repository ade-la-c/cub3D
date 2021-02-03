/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:08:56 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/03 18:56:49 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			lsthub(t_list *lst, t_file *file)
{
	char			*tmp;

	tmp = (char *)lst->content;
	if (!ft_strncmp(tmp, "R ", 2))
		parse_vec(tmp, &file->r, &file->parsed, 1);
	else if (!ft_strncmp(tmp, "NO ", 3))
		parse_path(tmp, &file->no, &file->parsed, 2);
	else if (!ft_strncmp(tmp, "SO ", 3))
		parse_path(tmp, &file->so, &file->parsed, 2);
	else if (!ft_strncmp(tmp, "WE ", 3))
		parse_path(tmp, &file->we, &file->parsed, 2);
	else if (!ft_strncmp(tmp, "EA ", 3))
		parse_path(tmp, &file->ea, &file->parsed, 2);
	else if (!ft_strncmp(tmp, "S ", 2))
		parse_path(tmp, &file->s, &file->parsed, 1);
	else if (!ft_strncmp(tmp, "F ", 2))
		parse_rgb(tmp, &file->f, &file->parsed, 1);
	else if (!ft_strncmp(tmp, "C ", 2))
		parse_rgb(tmp, &file->c, &file->parsed, 1);
	else if (file->parsed < 8)
	{
		printf("%d\n", file->parsed);	
		exit_error("FILE : A line is wrong");
	}
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
	file->parsed = 0;
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
//	system("leaks Cub3D");
	return (0);
}
