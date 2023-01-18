/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:36:11 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/09 22:36:12 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_set(t_fractal *f)
{
	t_julia	j;

	j.x = 0;
	while (j.x < f->screen_width)
	{
		j.y = 0;
		while (j.y < f->screen_height)
		{
			ft_julia_set2(&j, f);
			while (j.i < f->iter)
			{
				j.r_old = j.r_new;
				j.i_old = j.i_new;
				j.r_new = j.r_old * j.r_old - j.i_old * j.i_old + f->reel;
				j.i_new = 2 * j.r_old * j.i_old + f->im;
				if ((j.r_new * j.r_new + j.i_new * j.i_new) > 4)
					break ;
				j.i++;
			}
			ft_put_pixel(j.y, j.x, ft_color(j.i, f->iter), f);
			j.y++;
		}
		j.x++;
	}
}

void	ft_julia_set2(t_julia *j, t_fractal *f)
{
	j->r_new = (((j->x + f->x) / f->zoom / f->screen_width * 4 - 2));
	j->i_new = (((j->y + f->y) / f->zoom / f->screen_height * 4 - 2));
	j->i = 0;
}
