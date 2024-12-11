/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:53:13 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 13:59:09 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_struct *stack)
{
	int			max;
    int position;
    int max_position;

	max = INT_MIN;
    position = 1;
	max_position = 0;
	while (stack != NULL)
	{
		if (stack->content > max)
		{
			max = stack->content;
            max_position = position;
		}
		stack = stack->next;
        position++;
	}
	if (max == INT_MIN)
		max_position = 1;
	return (max_position);
}

int find_min(t_struct *stack)
{
	int			min;
    int position;
    int min_position;

	min = INT_MAX;
    position = 1;
    min_position = 0;
	while (stack != NULL)
	{
		if (stack->content < min)
		{
			min = stack->content;
            min_position = position;
		}
		stack = stack->next;
        position++;
	}
	if (min == INT_MAX)
		min_position = 1;
	return (min_position);
}

int	stack_sorted(t_struct *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_three(t_struct **stack_a)
{
    int position;

    position = find_max(*stack_a);
    if (position == 1)
        ft_rotate_a(stack_a, 1);
    else if (position == 2)
        ft_reverse_rotate_a(stack_a, 1);
    else if (position == 3)
    {
        if ((*stack_a)->content > (*stack_a)->next->content)
            ft_swap_a(*stack_a);
    }
    if ((*stack_a)->content > (*stack_a)->next->content)
            ft_swap_a(*stack_a);
}
