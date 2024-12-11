/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:54:28 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:23:38 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algorithm(t_struct **stack_a, t_struct **stack_b)
{
	ft_push_b(stack_a, stack_b);
	if (ft_structsize(*stack_a) > 3)
	{
		ft_push_b(stack_a, stack_b);
	}
	while (ft_structsize(*stack_a) > 3)
	{
		set_stacks(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b && *stack_b)
	{
		put_index(*stack_a);
		put_index(*stack_b);
		search_target_in_a(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	put_index(*stack_a);
	min_on_top(stack_a);
}

int	main(int argc, char **argv)
{
	t_struct	*stack_a;
	t_struct	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	stack_a = parsing(argc, argv);
	if (!stack_sorted(stack_a))
	{
		if (ft_structsize(stack_a) == 2)
			ft_swap_a(stack_a);
		else if (ft_structsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_algorithm(&stack_a, &stack_b);
	}
	ft_structclear(&stack_a);
	ft_structclear(&stack_b);
	return (0);
}
