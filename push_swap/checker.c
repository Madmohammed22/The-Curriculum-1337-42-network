/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:33:41 by mmad              #+#    #+#             */
/*   Updated: 2024/02/17 20:11:48 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	struct s_handler	checker;
	t_list				*stack_a;
	t_list				*stack_b;
	char				*arr;
	char				**s;

	if (argc == 1)
		exit(0);
	arr = ft_argv(argc, argv);
	if (arr == NULL)
		ft_exit_one();
	s = ft_split(arr, ' ');
	if (ft_check_if_valid(s, &checker) == 1 && ft_has_repeated_characters(s,
			checker.number2) == 1)
	{
		if (ft_checker(s, &stack_a, checker, &stack_b) == 0)
		{
			ft_display_result(&stack_a, &stack_b);
			ft_call_free(s, checker.number2, arr, ft_exit_zero);
		}
		ft_clean(&stack_a, &stack_b);
		ft_call_free(s, checker.number2, arr, ft_exit_one);
	}
	else
		ft_call_free(s, get_len(s), arr, ft_exit_one);
}
