/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:36:22 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/09 22:36:23 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_init_var(int ac, char **av, t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	f->screen_width = 1080;
	f->screen_height = 1080;
	if (ft_check_res(f) == 1)
		return (1);
	f->zoom = 1;
	f->movex = 0;
	f->movey = 0;
	if ((f->num == 1 && ac == 2) || (f->num == 2 && ac == 4))
		f->iter = 50;
	if (f->num == 1 && ac == 3)
		f->iter = ft_atoi(av[2]);
	if (f->num == 2 && (ac == 4 || ac == 5))
	{
		if (ft_check_num(av[2]) || ft_check_num(av[3]))
			return (1);
		f->reel = ft_atod(av[2]);
		f->im = ft_atod(av[3]);
	}
	if (f->num == 2 && ac == 5)
		f->iter = ft_atoi(av[4]);
	return (0);
}

int	main(int ac, char **av)
{
	int	num;

	num = 0;
	if (av[1])
		num = ft_atoi(av[1]);
	if (ft_put_errors(ac, num))
		return (1);
	return (ft_fractol(ac, av, num));
}
