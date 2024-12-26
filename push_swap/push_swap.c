/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:36:03 by mmad              #+#    #+#             */
/*   Updated: 2024/02/16 15:25:31 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action(char **s, char *arr, t_list *stack_a,
		struct s_handler checker)
{
	int			k;
	int			result;
	t_list		*stack_b;
	long long	value;
	int			sign;

	value = 0;
	sign = 1;
	k = 0;
	while (s[k] != NULL)
	{
		result = ft_atoi(s[k], &checker, sign, value);
		ft_push_linked_stack(&stack_a, checker.number);
		k++;
	}
	if (ft_check_if_sorted(&stack_a) == 1)
		ft_lstclear(&stack_a, del);
	else
	{
		stack_b = NULL;
		ft_call_sort(&stack_a, &stack_b, k);
		ft_lstclear(&stack_a, del);
	}
	ft_call_free(s, checker.number2, arr, ft_exit_zero);
}

int	main(int argc, char *argv[])
{
	struct s_handler	checker;
	t_list				*stack_a;
	char				*arr;
	char				**s;

	if (argc == 1)
		exit(0);
	stack_a = NULL;
	arr = ft_argv(argc, argv);
	if (arr == NULL)
		ft_exit_one();
	s = ft_split(arr, ' ');
	if (ft_check_if_valid(s, &checker) == 1 && ft_has_repeated_characters(s,
			checker.number2) == 1)
	{
		ft_action(s, arr, stack_a, checker);
	}
	else
		ft_call_free(s, get_len(s), arr, ft_exit_one);
	return (0);
}
