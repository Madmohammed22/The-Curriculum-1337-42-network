/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:48:59 by mmad              #+#    #+#             */
/*   Updated: 2024/03/21 22:26:58 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help(void)
{
	ft_printf("Execute 'mandelbrot' or 'julia'. If you choose 'julia',\n");
	ft_printf("follow it with two floating-point parameters.\n");
	exit(1);
}

void	ft_give_promt_back(int i, int argc, char **argv)
{
	i = 1;
	while (i < argc)
		ft_printf("%s\n", argv[i++]);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	int			i;

	if (argc == 1)
		ft_help();
	i = argc - 1;
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) && argc == 2)
		fractol.name = argv[1];
	else if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) && argc == 4
		&& ((is_float(argv[i]) && is_float(argv[i - 1]))
			|| (is_int(argv[i]) == 1 && is_int(argv[i - 1]) == 1)
			|| (is_int(argv[i]) == 1 && is_float(argv[i - 1]) == 1)
			|| (is_float(argv[i]) == 1 && is_int(argv[i - 1]) == 1)))
	{
		fractol.name = argv[1];
		fractol.x_0 = ft_atod(argv[i - 1]);
		fractol.y_0 = ft_atod(argv[i]);
	}
	else
		ft_give_promt_back(i, argc, argv);
	ft_call_window(&fractol);
	fractal_render(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
