/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:30:31 by mmad              #+#    #+#             */
/*   Updated: 2024/02/18 11:50:59 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	execute_instructions(char *ar, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp("sa\n", ar, 3) == 0)
		b_sa(stack_a);
	else if (ft_strncmp("sb\n", ar, 3) == 0)
		b_sb(stack_b);
	else if (ft_strncmp("ss\n", ar, 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp("pa\n", ar, 3) == 0)
		b_pa(stack_a, stack_b);
	else if (ft_strncmp("pb\n", ar, 3) == 0)
		b_pb(stack_a, stack_b);
	else if (ft_strncmp("ra\n", ar, 3) == 0)
		b_ra(stack_a);
	else if (ft_strncmp("rb\n", ar, 3) == 0)
		b_rb(stack_b);
	else if (ft_strncmp("rr\n", ar, 3) == 0)
		b_rr(stack_a, stack_b);
	else if (ft_strncmp("rra\n", ar, 4) == 0)
		b_rra(stack_a);
	else if (ft_strncmp("rrb\n", ar, 4) == 0)
		b_rrb(stack_b);
	else if (ft_strncmp("rrr\n", ar, 4) == 0)
		rrr(stack_a, stack_b);
	else
		return (free(ar), 1);
	return (0);
}

void	ft_build_list(char **s, t_list **stack_a, struct s_handler checker,
		long long value)
{
	int	k;
	int	result;
	int	sign;

	k = 0;
	sign = 1;
	while (s[k] != NULL)
	{
		result = ft_atoi(s[k], &checker, sign, value);
		ft_push_linked_stack(stack_a, checker.number);
		k++;
	}
}

int	ft_checker(char **s, t_list **stack_a, struct s_handler checker,
		t_list **stack_b)
{
	long long	value;
	char		*temp;

	*stack_a = NULL;
	*stack_b = NULL;
	value = 0;
	ft_build_list(s, stack_a, checker, value);
	temp = get_next_line(0);
	while (temp)
	{
		if (execute_instructions(temp, stack_a, stack_b) == 1)
			return (get_next_line(INVALID_READ), 1);
		free(temp);
		temp = get_next_line(0);
	}
	return (0);
}

void	ft_clean(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, del);
	ft_lstclear(stack_b, del);
}

void	ft_display_result(t_list **stack_a, t_list **stack_b)
{
	if ((ft_check_if_sorted(stack_a) == 1 && ft_lstsize(*stack_b) == 0))
		ft_putendl_fd("OK", 1);
	else if (ft_lstsize(*stack_a) == 1 && ft_lstsize(*stack_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_clean(stack_a, stack_b);
}
