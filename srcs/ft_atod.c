/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:35:48 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/09 22:35:48 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check_num(const char *str)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			p++;
		if (((str[i] < '0' || str[i] > '9') && str[i] != '.') || p > 1)
		{
			ft_putstr_fd("Format Error\n", 2);
			return (1);
		}
		if (str[i] == '.' && str[i + 1] == 0)
		{
			ft_putstr_fd("Format Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

double	ft_atod(const char *str)
{
	int		i;
	double	res;
	int		neg;

	i = 0;
	res = 0.00000;
	neg = 1;
	if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + str[i] - 48;
		i++;
	}
	res = res * neg;
	res = ft_atod2(str, i, res, neg);
	return (res);
}

double	ft_atod2(const char *str, int i, double res, int neg)
{
	double	f;
	double	base;

	f = 0.0;
	base = 0.1;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			f += base * (str[i] - 48);
			base /= 10.0;
			i++;
		}
		res += f * neg;
	}
	return (res);
}
