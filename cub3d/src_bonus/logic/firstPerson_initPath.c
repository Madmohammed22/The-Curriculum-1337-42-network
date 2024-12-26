/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstPerson_initPath.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:23:14 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 10:23:34 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pistol_path(t_weapon *weapon)
{
	weapon->img[0].path = "textures/firstPerson/attack-pistol/1.xpm";
	weapon->img[1].path = "textures/firstPerson/attack-pistol/2.xpm";
	weapon->img[2].path = "textures/firstPerson/attack-pistol/3.xpm";
	weapon->img[3].path = "textures/firstPerson/attack-pistol/4.xpm";
	weapon->img[4].path = "textures/firstPerson/attack-pistol/5.xpm";
	weapon->img[5].path = "textures/firstPerson/attack-pistol/6.xpm";
	weapon->img[6].path = "textures/firstPerson/attack-pistol/7.xpm";
	weapon->img[7].path = "textures/firstPerson/attack-pistol/8.xpm";
	weapon->img[8].path = "textures/firstPerson/attack-pistol/9.xpm";
	weapon->img[9].path = "textures/firstPerson/attack-pistol/10.xpm";
	weapon->img[10].path = "textures/firstPerson/attack-pistol/11.xpm";
	weapon->img[11].path = "textures/firstPerson/attack-pistol/12.xpm";
	weapon->img[12].path = "textures/firstPerson/attack-pistol/13.xpm";
}

void	set_knife_path(t_weapon *weapon)
{
	weapon->img[0].path = "textures/firstPerson/attack-knifestab/1.xpm";
	weapon->img[1].path = "textures/firstPerson/attack-knifestab/2.xpm";
	weapon->img[2].path = "textures/firstPerson/attack-knifestab/3.xpm";
	weapon->img[3].path = "textures/firstPerson/attack-knifestab/4.xpm";
	weapon->img[4].path = "textures/firstPerson/attack-knifestab/5.xpm";
}

void	set_hand_path(t_weapon *weapon)
{
	weapon->img[0].path = "textures/firstPerson/attack-punch/1.xpm";
	weapon->img[1].path = "textures/firstPerson/attack-punch/2.xpm";
	weapon->img[2].path = "textures/firstPerson/attack-punch/3.xpm";
	weapon->img[3].path = "textures/firstPerson/attack-punch/4.xpm";
	weapon->img[4].path = "textures/firstPerson/attack-punch/5.xpm";
	weapon->img[5].path = "textures/firstPerson/attack-punch/6.xpm";
	weapon->img[6].path = "textures/firstPerson/attack-punch/7.xpm";
	weapon->img[7].path = "textures/firstPerson/attack-punch/8.xpm";
	weapon->img[8].path = "textures/firstPerson/attack-punch/9.xpm";
	weapon->img[9].path = "textures/firstPerson/attack-punch/10.xpm";
	weapon->img[10].path = "textures/firstPerson/attack-punch/11.xpm";
	weapon->img[11].path = "textures/firstPerson/attack-punch/12.xpm";
	weapon->img[12].path = "textures/firstPerson/attack-punch/13.xpm";
	weapon->img[13].path = "textures/firstPerson/attack-punch/14.xpm";
	weapon->img[14].path = "textures/firstPerson/attack-punch/15.xpm";
	weapon->img[15].path = "textures/firstPerson/attack-punch/16.xpm";
	weapon->img[16].path = "textures/firstPerson/attack-punch/17.xpm";
	weapon->img[17].path = "textures/firstPerson/attack-punch/18.xpm";
	weapon->img[18].path = "textures/firstPerson/attack-punch/19.xpm";
	weapon->img[19].path = "textures/firstPerson/attack-punch/20.xpm";
	weapon->img[20].path = "textures/firstPerson/attack-punch/21.xpm";
	weapon->img[21].path = "textures/firstPerson/attack-punch/22.xpm";
	weapon->img[22].path = "textures/firstPerson/attack-punch/23.xpm";
}

void	set_machinegun_path(t_weapon *weapon)
{
	weapon->img[0].path = "textures/firstPerson/attack-machinegun/1.xpm";
	weapon->img[1].path = "textures/firstPerson/attack-machinegun/2.xpm";
	weapon->img[2].path = "textures/firstPerson/attack-machinegun/3.xpm";
	weapon->img[3].path = "textures/firstPerson/attack-machinegun/4.xpm";
	weapon->img[4].path = "textures/firstPerson/attack-machinegun/5.xpm";
	weapon->img[5].path = "textures/firstPerson/attack-machinegun/6.xpm";
	weapon->img[6].path = "textures/firstPerson/attack-machinegun/7.xpm";
	weapon->img[7].path = "textures/firstPerson/attack-machinegun/8.xpm";
	weapon->img[8].path = "textures/firstPerson/attack-machinegun/9.xpm";
	weapon->img[9].path = "textures/firstPerson/attack-machinegun/10.xpm";
	weapon->img[10].path = "textures/firstPerson/attack-machinegun/11.xpm";
	weapon->img[11].path = "textures/firstPerson/attack-machinegun/12.xpm";
	weapon->img[12].path = "textures/firstPerson/attack-machinegun/13.xpm";
	weapon->img[13].path = "textures/firstPerson/attack-machinegun/14.xpm";
	weapon->img[14].path = "textures/firstPerson/attack-machinegun/15.xpm";
	weapon->img[15].path = "textures/firstPerson/attack-machinegun/16.xpm";
	weapon->img[16].path = "textures/firstPerson/attack-machinegun/17.xpm";
	weapon->img[17].path = "textures/firstPerson/attack-machinegun/18.xpm";
	weapon->img[18].path = "textures/firstPerson/attack-machinegun/19.xpm";
	weapon->img[19].path = "textures/firstPerson/attack-machinegun/20.xpm";
	weapon->img[20].path = "textures/firstPerson/attack-machinegun/21.xpm";
	weapon->img[21].path = "textures/firstPerson/attack-machinegun/22.xpm";
}
