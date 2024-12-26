/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:59:49 by melfersi          #+#    #+#             */
/*   Updated: 2024/10/01 15:10:27 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*get_info(void)
{
	static t_info	info;

	return (&info);
}

void	ft_exit_param(void)
{
	printf("Execute 'Cub3d' \n");
	exit(1);
}

void	ft_give_prompt_back(int i, int argc, char **argv)
{
	i = 1;
	while (i < argc)
		printf("%s\n", argv[i++]);
	exit(1);
}

void	ft_parse_arguments(int argc, char **argv, t_condition *condition)
{
	int	i;

	if (argc == 1)
		ft_exit_param();
	i = argc - 1;
	if (!ft_strcmp(ft_strrchr(argv[1], '.'), ".cub") && argc == 2)
		condition->name = argv[1];
	else
		ft_give_prompt_back(i, argc, argv);
}

int	main(int argc, char **argv)
{
	t_info		*info;
	t_condition	game_condition;

	ft_parse_arguments(argc, argv, &game_condition);
	game_condition.substr = ft_create_two_dimensional_array(argv);
	if (move_on_if_map_valid_bonus(&game_condition) == false)
		return (EXIT_FAILURE);
	info = (t_info *)get_info();
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3d");
	init_map(info, &game_condition);
	init_player(info, &game_condition);
	init_texture(info, &game_condition);
	init_first_person_view(info);
	mlx_loop_hook(info->mlx, rendering, info);
	mlx_hook(info->win, ON_DESTROY, KEYPRESSMASK, ft_exit, info);
	mlx_hook(info->win, ON_KEYDOWN, KEYPRESSMASK, keypress, info);
	mlx_hook(info->win, ON_KEYUP, KEYRELEASEMASK, keyrelease, info);
	mlx_hook(info->win, ON_MOUSEDOWN, BUTTONPRESSMASK, mousepress, info);
	mlx_hook(info->win, ON_MOUSEUP, BUTTONRELEASEMASK, mouserelease, info);
	mlx_hook(info->win, MOTIONNOTIFY, MOTIONNOTIFYMASK, mousemove, info);
	mlx_loop(info->mlx);
	ft_hunt_leak();
	return (EXIT_SUCCESS);
}
