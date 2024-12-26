/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:17:11 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 21:21:27 by mohammedmad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include "mlx.h"
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "structs.h"
# include "enums.h"
# include "pars_cub3d.h"
# include "macros.h"

int				ft_exit(t_info *mlx);
void			*get_info(void);
int				keypress(int keycode, t_info *mlx);
int				keyrelease(int keycode, t_info *mlx);
int				rendering(t_info *info);
void			my_mlx_pixel_set(t_data *data, int x, int y, int color);
void			init_map(t_info *mlx, t_condition *condition);
void			init_player(t_info *mlx, t_condition *condition);
void			init_texture(t_info *info, t_condition *condition);
void			init_img_data(t_info *mlx);
void			rect(t_data *data, t_rect rect);
void			rect_cir(t_data *data, t_rect_cir rect_cir);
void			draw_cir(t_data *data, t_cir cir);
void			draw_line(t_data *data, t_line line);
double			deg_to_rad(double deg);
uint32_t		rgb_int(int r, int g, int b);
uint32_t		argb(uint32_t src_color, uint32_t bg_color, float alpha);
void			raycasting(t_info *info);
void			update_3d(t_info *info);
void			render_rays(t_info *mlx);
void			update_player_position(t_info *info);
void			update_minimap_player(t_info *info);
double			normalize_angle(double angle);
void			set_horizonal_intersection(t_info *info, t_intersec *intersec,
					int id, int type_hit);
void			set_vertical_intersection(t_info *info, t_intersec *intersec,
					int id, int type_hit);
t_type			hit(t_info *info, double x, double y);
double			distence_ray(t_info *info, double x, double y);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);

#endif
