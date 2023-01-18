/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:36:18 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/09 22:36:19 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_press(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int	ft_close_win(void)
{
	exit(0);
}

int	ft_mouse_hook(int key, int x, int y, t_fractal *f)
{
	if (key == 4)
	{
		f->zoom *= 1.1;
		f->x = (f->x + ((f->screen_width - (f->screen_width / 1.1)) / 2)
				+ (x - f->screen_width / 2) * (1 - (1 / 1.1))) * 1.1;
		f->y = (f->y + ((f->screen_width - (f->screen_width / 1.1)) / 2)
				+ (y - f->screen_width / 2) * (1 - (1 / 1.1))) * 1.1;
	}
	if (key == 5)
	{
		f->zoom /= 1.1;
		f->x = f->x / 1.1 - ((f->screen_width - (f->screen_width / 1.1)) / 2)
			/ 1.1 -(x - f->screen_width / 2) * 1.1 + (x - f->screen_width / 2);
		f->y = f->y / 1.1 - ((f->screen_width - (f->screen_width / 1.1)) / 2)
			/ 1.1 -(y - f->screen_width / 2) * 1.1 + (y - f->screen_width / 2);
	}
	return (0);
}
