/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:02:06 by mmad              #+#    #+#             */
/*   Updated: 2024/03/21 14:29:37 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/nfs/homes/mmad/Desktop/fractol_cursus/fractol/ft_printf/ft_printf.h"
# include "/nfs/homes/mmad/Desktop/fractol_cursus/fractol/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PSYCHEDELIC_PURPLE 0x660066

# define Plus 0x003d
# define Minus 0x002d
# define Escape 0xff1b
# define Left 0xff51
# define Up 0xff52
# define Right 0xff53
# define Down 0xff54
# define Plus 0x003d
# define Minus 0x002d
# define XK_a 0x0061
# define XK_d 0x0064

typedef struct s_data
{
	double	x;
	double	y;
	double	temp;
}			t_data;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bit_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_ptr;
	void	*window;
	t_img	img;
	int		max_iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	x_0;
	double	y_0;
	double	x0;
	double	y0;
	double	x;
	double	y;
	int		flag;
	double	temp;
	int		range;
}			t_fractol;

double		ft_atod(char *s);
int			is_int(char *argv);
int			is_float(const char *string);

void		ft_call_window(t_fractol *fractal);
void		ft_pixel_put(int x, int y, t_img *img, int color);
void		fractal_render(t_fractol *fractal);
double		ft_coordinates(double unscaled_num, double new_min, double new_max,
				double prev_max);
int			ft_handle_key(int keysym, t_fractol *fractal);
int			ft_close(t_fractol *fractal);
void		ft_add_data(t_fractol *fractal);
int			calculate_color(float iter, t_fractol *fractol);
int			calculate_color_bonus(float iter, t_fractol *fractol);
void		ft_get_constant(t_data *z, t_data *constant, t_fractol *fractal);
int			ft_calculate(int x, int y, t_fractol *fractal);
int			ft_handle_mouse(int button, int x, int y, t_fractol *fractal);
int			ft_handle_mouse_track(int button, int x, int y, t_fractol *fractal);

#endif
