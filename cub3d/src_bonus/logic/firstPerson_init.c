/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstPerson_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:19:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 11:01:28 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pistol_path(t_weapon *weapon);

t_weapon	init_pistol(void)
{
	t_weapon	weapon;

	weapon.n_frames = PISTOL_FRAMES;
	weapon.img = ft_malloc(sizeof(t_img) * (weapon.n_frames));
	set_pistol_path(&weapon);
	weapon.is_aiming = false;
	weapon.is_shooting = false;
	weapon.is_kneeling = false;
	weapon.is_whiping = false;
	weapon.is_guarding = false;
	weapon.whiping_frame = 9;
	weapon.whiping_frame_max = 12;
	weapon.shooting_frame = 2;
	weapon.shooting_frame_max = 6;
	weapon.aiming_frame = 2;
	weapon.aiming_frame_max = 2;
	weapon.kneeling_frame = 0;
	weapon.kneeling_frame_max = 0;
	weapon.delay_frame = 100;
	return (weapon);
}

void	set_knife_path(t_weapon *weapon);

t_weapon	init_knife(void)
{
	t_weapon	weapon;

	weapon.n_frames = KNIFE_FRAMES;
	weapon.img = ft_malloc(sizeof(t_img) * (weapon.n_frames));
	set_knife_path(&weapon);
	weapon.is_aiming = false;
	weapon.is_shooting = false;
	weapon.is_kneeling = false;
	weapon.is_whiping = false;
	weapon.is_guarding = false;
	weapon.shooting_frame = 2;
	weapon.shooting_frame_max = 3;
	weapon.aiming_frame = 2;
	weapon.aiming_frame_max = 2;
	weapon.delay_frame = 100;
	return (weapon);
}

void	set_hand_path(t_weapon *weapon);

t_weapon	init_hand(void)
{
	t_weapon	weapon;

	weapon.n_frames = 23;
	weapon.img = ft_malloc(sizeof(t_img) * (weapon.n_frames));
	set_hand_path(&weapon);
	weapon.is_aiming = false;
	weapon.is_shooting = false;
	weapon.is_kneeling = false;
	weapon.is_whiping = false;
	weapon.is_guarding = false;
	weapon.shooting_frame = 1;
	weapon.shooting_frame_max = 5;
	weapon.aiming_frame = 6;
	weapon.aiming_frame_max = 9;
	weapon.whiping_frame = 10;
	weapon.whiping_frame_max = 16;
	weapon.kneeling_frame = 18;
	weapon.kneeling_frame_max = 22;
	weapon.delay_frame = 100;
	return (weapon);
}

void	set_machinegun_path(t_weapon *weapon);

t_weapon	init_machinegun(void)
{
	t_weapon	weapon;

	weapon.n_frames = 22;
	weapon.img = ft_malloc(sizeof(t_img) * (weapon.n_frames));
	set_machinegun_path(&weapon);
	weapon.is_aiming = false;
	weapon.is_shooting = false;
	weapon.is_kneeling = false;
	weapon.is_whiping = false;
	weapon.is_guarding = false;
	weapon.shooting_frame = 2;
	weapon.shooting_frame_max = 16;
	weapon.aiming_frame = 1;
	weapon.aiming_frame_max = 1;
	weapon.whiping_frame = 18;
	weapon.whiping_frame_max = 21;
	weapon.kneeling_frame = 0;
	weapon.kneeling_frame_max = 0;
	weapon.delay_frame = 100;
	return (weapon);
}

t_weapon	init_weapon(t_weapon_type type)
{
	if (type == PISTOL)
		return (init_pistol());
	if (type == KNIFE)
		return (init_knife());
	if (type == HAND)
		return (init_hand());
	if (type == MACHINEGUN)
		return (init_machinegun());
	return (init_pistol());
}
