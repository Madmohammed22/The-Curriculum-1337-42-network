/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstPerson.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:24:08 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 10:55:58 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_status(t_info *info, int indx)
{
	int		start_x;
	int		start_y;

	if (info->weapon[info->active_weapon_id].n_frames <= indx)
		indx = 0;
	start_x = (WIDTH / 2)
		- (info->weapon[info->active_weapon_id].img[indx].width / 2);
	start_y = HEIGHT - info->weapon[info->active_weapon_id].img[indx].height;
	draw_img(&info->map.data, info->weapon[info->active_weapon_id].img[indx],
		start_x, start_y);
}
void	shooting(int *idx, t_weapon weapon);
void	aiming(int *idx, t_weapon weapon);
void	whiping(int *idx, t_weapon weapon);
void	kneeling(int *idx, t_weapon weapon);

void	first_person_view(t_info *info)
{
	static int		idx = 0;
	static clock_t	last_time = 0;
	clock_t			current_time;
	double			diff_time;

	current_time = clock();
	diff_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 1000;
	if (diff_time > info->weapon[info->active_weapon_id].delay_frame)
	{
		last_time = current_time;
		if (info->weapon[info->active_weapon_id].is_shooting)
			shooting(&idx, info->weapon[info->active_weapon_id]);
		else if (info->weapon[info->active_weapon_id].is_aiming)
			aiming(&idx, info->weapon[info->active_weapon_id]);
		else if (info->weapon[info->active_weapon_id].is_whiping)
			whiping(&idx, info->weapon[info->active_weapon_id]);
		else if (info->weapon[info->active_weapon_id].is_guarding)
			idx = 17;
		else if (info->weapon[info->active_weapon_id].is_kneeling)
			kneeling(&idx, info->weapon[info->active_weapon_id]);
		else
			idx = 0;
	}
	update_player_status(info, idx);
}
