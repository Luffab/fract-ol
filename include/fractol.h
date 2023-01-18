/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:35:05 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/09 22:35:09 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_fractal
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*data;
	double	zoom;
	double	x;
	double	y;
	double	movex;
	double	movey;
	double	reel;
	double	im;
	int		screen_width;
	int		screen_height;
	int		iter;
	int		num;
	int		bpp;
	int		sizeline;
	int		endian;
	int		r;
	int		g;
	int		b;
}				t_fractal;

typedef struct s_mandelbrot
{
	double	r_pixel;
	double	i_pixel;
	double	r_new;
	double	r_old;
	double	i_new;
	double	i_old;
	int		x;
	int		y;
	int		i;
}				t_mandelbrot;

typedef struct s_julia
{
	double	r_new;
	double	r_old;
	double	i_new;
	double	i_old;
	int		x;
	int		y;
	int		i;
}				t_julia;

double	ft_atod(const char *str);
int		ft_init_var(int ac, char **av, t_fractal *f);
void	ft_mandelbrot_set(t_fractal *f);
int		ft_fractol(int ac, char **av, int num);
void	ft_put_pixel(int x, int y, int rgb, t_fractal *f);
int		ft_color(int i, int iter);
void	ft_put_rgb(t_fractal *f, int x, int y);
int		ft_key_press(int key);
int		ft_close_win(void);
int		ft_mouse_hook(int key, int x, int y, t_fractal *f);
int		ft_loop_hook(t_fractal *f);
void	ft_julia_set(t_fractal *f);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_julia_set2(t_julia *j, t_fractal *f);
int		ft_check_arg(int num, int ac, char **av);
int		ft_check_res(t_fractal *f);
double	ft_atod2(const char *str, int i, double res, int neg);
int		ft_check_arg2(char **av, int i);
int		ft_put_errors(int ac, int num);
int		ft_check_num(const char *str);
#endif