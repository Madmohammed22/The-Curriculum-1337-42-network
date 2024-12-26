/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:18:58 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 14:48:48 by melfersi         ###   ########.fr       */
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
}	t_texture_direction;

typedef enum e_type
{
	EMPTY,
	WALL = 1,
}	t_type;

#endif
