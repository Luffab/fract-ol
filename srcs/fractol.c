/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:35:42 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/09 22:35:44 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_choose_set(t_fractal *f)
{
	mlx_clear_window(f->mlx, f->win);
	if (f->num == 1)
		ft_mandelbrot_set(f);
	else if (f->num == 2)
		ft_julia_set(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	ft_loop_hook(t_fractal *f)
{
	ft_choose_set(f);
	return (0);
}

int	ft_init_window(int ac, char **av, t_fractal *f)
{
	if (ft_init_var(ac, av, f) == 0)
	{
		f->mlx = mlx_init();
		f->win = mlx_new_window(f->mlx, f->screen_width,
				f->screen_height, "Fract-ol");
		f->img = mlx_new_image (f->mlx, f->screen_width, f->screen_height);
		f->data = mlx_get_data_addr(f->img, &f->bpp, &f->sizeline, &f->endian);
		mlx_loop_hook(f->mlx, ft_loop_hook, f);
		mlx_key_hook(f->win, ft_key_press, f);
		mlx_mouse_hook(f->win, ft_mouse_hook, f);
		mlx_hook(f->win, 17, 0, ft_close_win, f);
		mlx_loop(f->mlx);
		return (0);
	}
	return (1);
}

int	ft_fractol(int ac, char **av, int num)
{
	t_fractal	f;

	f.num = num;
	if (ft_check_arg(num, ac, av) == 0)
		return (ft_init_window(ac, av, &f));
	return (1);
}
