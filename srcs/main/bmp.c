/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:33:28 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/03 18:09:03 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"





static void				bmp_data(t_glb *glb, int fd)
{
	int					i;
	int					j;
	u_int32_t			pxl;

	i = glb->file->r.y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < glb->file->r.x)
		{
			pxl = glb->mlibx->addr[i * glb->mlibx->line_length / 4 + j];
			if ((write(fd, &pxl, 4)) != 4)
				exit_error("BMP : fail writing pixel");
			j++;
		}
		i--;
	}
}





static void				bmp_header(t_glb *glb, int imgsize, int fd)
{
	u_int8_t			header[54];
	int					filesize;

	filesize = imgsize + 54;
	ft_bzero(header, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &filesize, 4);
	ft_memcpy(header + 10, &(int){54}, 4);
	ft_memcpy(header + 14, &(int){40}, 4);
	ft_memcpy(header + 18, &glb->file->r.x, 4);
	ft_memcpy(header + 22, &glb->file->r.y, 4);
	ft_memcpy(header + 26, &(int){1}, 2);
	ft_memcpy(header + 28, &(int){32}, 2);
	ft_memcpy(header + 34, &imgsize, 4);
	if ((write(fd, header, 54)) != 54)
		exit_error("BMP : bitshifting error");
}





void					save_bmp(t_glb *glb)
{
	int					fd;
	int					imgsize;

	imgsize = glb->file->r.x * glb->file->r.y * 4;
	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU)) < 0)
		exit_error("BMP : read error");
	bmp_header(glb, imgsize, fd);
	bmp_data(glb, fd);
	close(fd);
	fd = -1;
}
