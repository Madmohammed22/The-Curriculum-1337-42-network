/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:55:53 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 14:57:57 by melfersi         ###   ########.fr       */
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
# include <time.h>
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
void			draw_img(t_data *data, t_img img, int x, int y);
double			deg_to_rad(double deg);
uint32_t		rgb_int(int r, int g, int b);
uint32_t		argb(uint32_t src_color, uint32_t bg_color, float alpha);
void			raycasting(t_info *info);
void			update_3d(t_info *info);
void			render_rays(t_info *mlx);
void			update_minimap(t_info *info);
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
void			door_key(t_info *info);
int				mousepress(int button, int x, int y, t_info *info);
int				mouserelease(int button, int x, int y, t_info *info);
int				mousemove(int x, int y, t_info *info);
void			first_person_view(t_info *info);
void			init_first_person_view(t_info *info);
bool			bfs_main_loop(char **new_map, t_queue **front, t_queue **rear);
int				ft_contain_only_digit(char *str);
t_weapon		init_weapon(t_weapon_type type);

#endif
