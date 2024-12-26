/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:58:08 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 14:58:55 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_texture_direction
{
	NORTH_ID,
	SOUTH_ID,
	EAST_ID,
	WEST_ID,
	DOOR_ID
}	t_texture_direction;

typedef enum e_type
{
	EMPTY,
	WALL = 1,
	C_DOOR = 4,
	O_DOOR = 8
}	t_type;

typedef enum e_weapon_type
{
	PISTOL,
	KNIFE,
	HAND,
	MACHINEGUN
}	t_weapon_type;

#endif
