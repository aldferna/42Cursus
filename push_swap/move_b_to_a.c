/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:09:11 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:21:03 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_target_in_a(t_struct *stack_a, t_struct *stack_b)
{
	int			target_nbr;
	t_struct	*aux;

	aux = stack_a;
	while (stack_b)
	{
		target_nbr = INT_MAX;
		while (stack_a)
		{
			if (stack_a->content > stack_b->content && stack_a->content < target_nbr)
			{
				target_nbr = stack_a->content;
				stack_b->target_index = stack_a->index;
			}
			stack_a = stack_a->next;
		}
		stack_a = aux;
		if (target_nbr == INT_MAX)
			stack_b->target_index = find_min(stack_a);
		stack_b = stack_b->next;
	}
}
void	move_b_to_a_mix1(t_struct **stack_a, t_struct **stack_b, int a_below,
		int b_above, char name)
{
	while (b_above - 1 > 0)
	{
		ft_rotate_a(stack_b, 1);
		b_above -= 1;
	}
	while (a_below > 0)
	{
		ft_reverse_rotate_a(stack_a, 1);
		a_below -= 1;
	}
	if (name == 'a')
		ft_push_b(stack_a, stack_b);
	else
		ft_push_a(stack_a, stack_b);
}

void	move_b_to_a(t_struct **stack_a, t_struct **stack_b)
{
	const int	half_a = (ft_structsize(*stack_a) + 1) / 2;
	int			a_below;

	a_below = ft_structsize(*stack_a) - (*stack_b)->target_index + 1;
	if ((*stack_b)->above == 1 && (*stack_b)->target_index <= half_a)
		move_a_to_b_above(stack_a, stack_b, (*stack_b)->target_index, (*stack_b)->index, 'b');
	else if ((*stack_b)->above == 1 && (*stack_b)->target_index > half_a)
		move_b_to_a_mix1(stack_a, stack_b, a_below, (*stack_b)->index, 'b');
	return ;
}

void	min_on_top(t_struct **stack_a)
{
	int min = find_min(*stack_a);
	int half;
	int below;

	half = (ft_structsize(*stack_a) + 1) / 2;
	below = ft_structsize(*stack_a) - min + 1;
	if (min != 1)
	{
		if (min <= half)
		{
			while ((min - 1) > 0)
			{
				ft_rotate_a(stack_a, 1);
				min--;
			}
		}
		else if (min > half)
		{
			while (below > 0)
			{
				ft_reverse_rotate_a(stack_a, 1);
				below--;
			}
		}
	}
}
