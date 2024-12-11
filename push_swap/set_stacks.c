/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:23:58 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 18:45:44 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void put_index(t_struct *stack)
{
    long i;
	long half;

	half = (ft_structsize(stack) + 1) / 2;
	i = 1;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= half)
			stack->above = 1;
		else
			stack->above = 0;
		i++;
		stack = stack->next;
	}
}

void	search_target_in_b(t_struct *stack_a, t_struct *stack_b)
{
	int target_nbr;
	t_struct *aux;

	aux = stack_b;
	while (stack_a != NULL)
	{
		target_nbr = INT_MIN;
		while (stack_b != NULL)
		{
			//printf("%i %i %i\n", stack_b->content, stack_a->content, target_nbr);
			if (stack_b->content < stack_a->content && stack_b->content > target_nbr)
			{
				target_nbr = stack_b->content;
				stack_a->target_index = stack_b->index;
			}
			stack_b = stack_b->next;
		}
		stack_b = aux;
		if (target_nbr == INT_MIN)
			stack_a->target_index = find_max(stack_b);
		//printf("find_max en B: %i\n", find_max(stack_b));
		stack_a = stack_a->next;
	}
}

void    set_cost(t_struct *stack_a, t_struct *stack_b)
{
    int half_b;
    int a_below;
    int b_below;
    t_struct *aux;
 
    half_b = (ft_structsize(stack_b) + 1) / 2;
    aux = stack_a;
    while (stack_a)
    {
        a_below = ft_structsize(aux) - stack_a->index + 1;
        b_below = ft_structsize(stack_b) - stack_a->target_index + 1;

        if (stack_a->above == 1 && stack_a->target_index <= half_b)
            stack_a->push_cost = (stack_a->index > stack_a->target_index ? stack_a->index : stack_a->target_index) - 1;
        else if (stack_a->above == 0 && stack_a->target_index > half_b)
            stack_a->push_cost = (a_below > b_below ? a_below : b_below);
        else if (stack_a->above == 1 && stack_a->target_index > half_b)
            stack_a->push_cost = (stack_a->index - 1) + b_below;
        else if (stack_a->above == 0 && stack_a->target_index <= half_b)
            stack_a->push_cost = a_below + (stack_a->target_index - 1);
        stack_a = stack_a->next;
    }
}

void set_cheapest(t_struct *stack_a)
{
    int cheapest;
    t_struct *cheapest_node;
    
    cheapest = stack_a->push_cost;
	stack_a->cheapest = 1;
	cheapest_node = stack_a;
	stack_a = stack_a->next;
    while (stack_a)
    {
        if (stack_a->push_cost < cheapest)
        {
            cheapest = stack_a->push_cost;
            stack_a->cheapest = 1;
            cheapest_node->cheapest = 0;
			cheapest_node = stack_a;
        }
        stack_a = stack_a->next;
    }
}

void set_stacks(t_struct *stack_a, t_struct *stack_b)
{
	put_index(stack_a);
	put_index(stack_b);
	search_target_in_b(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_cheapest(stack_a);
	// while (stack_a)
	// {
	// 	printf("--target: %i\n", stack_a->target_index);
	// 	printf("cost: %i\n", stack_a->push_cost);
	// 	printf("     cheapest: %i\n", stack_a->cheapest);
	// 	stack_a = stack_a->next;
	// }
	return;
}
