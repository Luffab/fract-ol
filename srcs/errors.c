/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:35:35 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/09 22:35:37 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_put_errors(int ac, int num)
{
	if ((num == 1 && ac < 2) || (num == 2 && ac < 4))
	{
		ft_putstr_fd("Error\nNOT_ENOUGH_ARGUMENTS\n", 1);
		return (1);
	}
	else if ((num == 1 && ac > 3) || (num == 2 && ac > 5))
	{
		ft_putstr_fd("Error\nTOO_MANY_ARGUMENTS\n", 1);
		return (1);
	}
	else if (num < 1 || num > 2)
	{
		ft_putstr_fd("Error\nEntrez 1 pour Mandelbrot ou 2 pour Julia\n", 1);
		return (1);
	}
	return (0);
}

int	ft_check_res(t_fractal *f)
{
	if (f->screen_width <= 0 || f->screen_height <= 0)
	{
		ft_putstr_fd("Error\nRESOLUTION_ERROR\n", 1);
		return (1);
	}
	if (f->screen_width > 2560)
		f->screen_width = 2560;
	if (f->screen_height > 1440)
		f->screen_height = 1440;
	return (0);
}

int	ft_check_arg(int num, int ac, char **av)
{
	int	i;

	i = 0;
	if (num == 1 && ac == 3)
		return (ft_check_arg2(av, 2));
	else if (num == 2 && ac == 5)
		return (ft_check_arg2(av, 4));
	return (0);
}

int	ft_check_arg2(char **av, int i)
{
	int	j;

	j = 0;
	while (av[i][j])
	{
		if (av[i][j] < '0' || av[i][j] > '9')
		{
			ft_putstr_fd("Error\nIterations must be of type int\n", 1);
			return (1);
		}
		j++;
	}
	return (0);
}
