/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:20:39 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/03/03 12:12:35 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int				exit_hook(t_glb *glb)
{
	final_free(glb);
	exit_error("close window");
	return (0);
}

static int				keyrelease_hook(int key, t_glb *glb)
{
	if (key == KEYCODE_ESC)
	{
		final_free(glb);
		exit_error("Merci pour les services.");
	}
	if (key == KEYCODE_W)
		mv_forward(glb->pos, glb->map);
	if (key == KEYCODE_S)
		mv_backward(glb->pos, glb->map);
	if (key == KEYCODE_A)
		mv_left(glb->pos, glb->map);
	if (key == KEYCODE_D)
		mv_right(glb->pos, glb->map);
	if (key == KEYCODE_RIGHTARROW)
		rotate_right(glb->pos);
	if (key == KEYCODE_LEFTARROW)
		rotate_left(glb->pos);
	return (0);
}

static int				keypress_hook(int key, t_glb *glb)
{
	if (key == KEYCODE_ESC)
	{
		mlx_destroy_image(glb->mlibx->mlx_ptr, glb->mlibx->img);
		final_free(glb);
		exit_error("Merci pour les services.");
	}
	if (key == KEYCODE_W)
		mv_forward(glb->pos, glb->map);
	if (key == KEYCODE_S)
		mv_backward(glb->pos, glb->map);
	if (key == KEYCODE_A)
		mv_left(glb->pos, glb->map);
	if (key == KEYCODE_D)
		mv_right(glb->pos, glb->map);
	if (key == KEYCODE_RIGHTARROW)
		rotate_right(glb->pos);
	if (key == KEYCODE_LEFTARROW)
		rotate_left(glb->pos);
	return (0);
}

/*
**	key_hooks s'occupe des controles dans le jeu et lance la suite de l'algo
*/

static int				key_hooks(t_glb *glb)
{
	int					key;

	key = 36;
	keypress_hook(key, glb);
	keyrelease_hook(key, glb);
	mlx_put_image_to_window(glb->mlibx->mlx_ptr, glb->mlibx->mlx_win,
							glb->mlibx->img, 0, 0);
	algo_raycasting(glb);
	return (1);
}

void					hook_loop(int ac, t_glb *glb)
{
	if (ac == 2)
	{
		minilibx_setup(glb->mlibx, glb->file);
		mlx_hook(glb->mlibx->mlx_win, XEVENT_KEYPRESS, 0, &keypress_hook,
				(void *)glb);
		mlx_hook(glb->mlibx->mlx_win, XEVENT_KEYRELEASE, 0, &keyrelease_hook,
				(void *)glb);
		mlx_hook(glb->mlibx->mlx_win, XEVENT_EXIT, 0, &exit_hook, (void *)glb);
		mlx_loop_hook(glb->mlibx->mlx_ptr, &key_hooks, (void *)glb);
		mlx_loop(glb->mlibx->mlx_ptr);
	}
	if (ac == 3)
	{
		minilibx_setup(glb->mlibx, glb->file);
		algo_raycasting(glb);
		save_bmp(glb);
	}
	return ;
}
