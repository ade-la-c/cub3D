/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:33 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/04 16:19:38 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int				main(void)
{
	void		*mlx_ptr;
	void		*window;
	void		*image;
	int			bpp;
	int			sl;
	int			endian;
	char		*image_data;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 600, 600, "oui");
	image = mlx_new_image(mlx_ptr, 100, 100);
	image_data = mlx_get_data_addr(image, &bpp, &sl, &endian);
	image_data[0] = 0;
	image_data[1] = 0;
	image_data[2] = (char)255;
	mlx_put_image_to_window(mlx_ptr, window, image, 150, 150);
	mlx_loop(mlx_ptr);
	return (0);
}
*/

int main(void)
{
	char *filepath = "./assets/file.cub";

	file_to_lst(filepath);
	//	system("leaks Cub3D");
	return (0);
}
