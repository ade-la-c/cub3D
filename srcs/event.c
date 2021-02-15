/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:20:39 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/02/15 19:51:03 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int				exit_hook(void *x)
{
	free_file((t_file *)x, "Close window");
	return (0);
}

static int				keyrelease_hook(int key, t_glb *glb)
{
	if (key == KEYCODE_ESC)
		ft_error_exit("Merci pour les services.");
	if (key == KEYCODE_W)
		ft_mvforward(glb->pos, glb->map);
	if (key == KEYCODE_S)
		ft_mvbackward(glb->pos, glb->map);
	if (key == KEYCODE_A)
		ft_mvleft(glb->pos, glb->map);
	if (key == KEYCODE_D)
		ft_mvright(glb->pos, glb->map);
	if (key == KEYCODE_RIGHTARROW)
		ft_rotate_right(glb->pos);
	if (key == KEYCODE_LEFTARROW)
		ft_rotate_left(glb->pos);
	return (0);
}

static int				keypress_hook(int key, t_glb *glb)
{
	if (key == KEYCODE_ESC)
		exit_error("Merci pour les services.");
	if (key == KEYCODE_W)
		ft_mvforward(glb->pos, glb->map);
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

int						ft_test(t_glb *glb)
{
	int					key;

	key = 36;
	keypress_hook(key, glb);
	keyrelease_hook(key, glb);
	affichage(glb);
	mlx_put_image_to_window(glb->mlibx->mlx_ptr, glb->mlibx->mlx_win,
							glb->mlibx->img, 0, 0);
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
		mlx_loop_hook(glb->mlibx->mlx_ptr, &ft_test, (void *)glb);
	}
	return ;
}
