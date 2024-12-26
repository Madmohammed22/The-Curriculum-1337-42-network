/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstPerson_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:24:08 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 18:07:25 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shooting(int *idx, t_weapon weapon)
{
	if (*idx < weapon.shooting_frame)
		*idx = weapon.shooting_frame;
	if (*idx < weapon.shooting_frame_max)
		(*idx)++;
	else
		*idx = weapon.shooting_frame;
}

void	aiming(int *idx, t_weapon weapon)
{
	if (*idx < weapon.aiming_frame)
		*idx = weapon.aiming_frame;
	if (*idx < weapon.aiming_frame_max)
		(*idx)++;
	else
		*idx = weapon.aiming_frame;
}

void	whiping(int *idx, t_weapon weapon)
{
	if (*idx < weapon.whiping_frame)
		*idx = weapon.whiping_frame;
	if (*idx < weapon.whiping_frame_max)
	{
		(*idx)++;
	}
	else
		*idx = weapon.whiping_frame;
}

void	kneeling(int *idx, t_weapon weapon)
{
	if (*idx < weapon.kneeling_frame)
		*idx = weapon.kneeling_frame;
	if (*idx < weapon.kneeling_frame_max)
		(*idx)++;
	else
		*idx = weapon.kneeling_frame;
}
