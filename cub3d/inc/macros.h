/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:19:53 by melfersi          #+#    #+#             */
/*   Updated: 2024/10/01 08:49:44 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// events 
// events masks
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 2
# define BUTTONPRESSMASK 4
# define BUTTONRELEASEMASK 8
# define MOTIONNOTIFY 6
# define MOTIONNOTIFYMASK 64
// events codes
# define ON_MOUSEMOVE 6
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 2
// keycodes
# define ESC 65307
# define LEFT_SHIFT 65505
# define SPACE 32
# define NUM_1 49
# define NUM_2 50
# define NUM_3 51
# define NUM_4 52
# define R 114
# define M 109
# define W 119
# define S 115
# define A 97
# define D 100
# define E 101
# define G 103
# define Q 113
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define SCROLL_CLICK 2

// resolution
# define HEIGHT 400
# define WIDTH 800
// textures
# define MOVE_SPEED 3
# define ROTATION_SPEED 1.5
# define PLAYER_RADIUS 9
# define T_SIZE 64
# define MINIMAP_SCALE_FAC 0.5
# define STRIP_WIDTH 1
# define NUM_RAYS WIDTH
# define FOV_ANGLE 60

// colors
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF
# define BROWN 0x00820421
# define DARK_BROWN 0x0041393c
# define CYAN 0x0000FFFF
# define GREEN 0x0000FF00

// player directions
# define NORTH_P 1.570796
# define EAST_P 0.0
# define SOUTH_P 4.712389
# define WEST_P 3.141593

#endif