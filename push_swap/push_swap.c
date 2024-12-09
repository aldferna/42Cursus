/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:54:28 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/09 19:43:14 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_a_to_b_above(t_struct **stack_a, t_struct **stack_b)
{
	while ((*stack_a)->index - 1 != 0 && (*stack_a)->target_index - 1 != 0)
	{
		ft_rr(stack_a, stack_b);
		(*stack_a)->index -= 1;
		(*stack_a)->target_index -= 1;
	}
	if ((*stack_a)->index - 1 > (*stack_a)->target_index - 1)
	{
		while ((*stack_a)->index - 1 > 0)
		{
			ft_rotate_a(stack_a);
			(*stack_a)->index -= 1;
		}
	}
	else if ((*stack_a)->target_index - 1 > (*stack_a)->index - 1)
	{
		while ((*stack_a)->target_index - 1 > 0)
		{
			ft_rotate_b(stack_b);
			(*stack_a)->target_index -= 1;
		}
	}
	/*printf("lista AAAAA\n");
	print_stack(*stack_a);*/
	ft_push_b (stack_a, stack_b);
	return;
}

void move_a_to_b_below(t_struct **stack_a, t_struct **stack_b, int a_below, int b_below)
{
	while (a_below != 0 && b_below != 0)
	{
		ft_rrr(stack_a, stack_b);
		a_below -= 1;
		b_below -= 1;
	}
	if (a_below > b_below)
	{
		while (a_below > 0)
		{
			ft_reverse_rotate_a(stack_a);
			a_below -= 1;
		}
	}
	else if (a_below < b_below)
	{
		while (b_below > 0)
		{
			ft_reverse_rotate_b(stack_b);
			b_below -= 1;
		}
	}
	/*printf("lista AAbelow\n");
	print_stack(*stack_a);*/
	ft_push_b (stack_a, stack_b);
	return;
}

void move_a_to_b_mix1(t_struct **stack_a, t_struct **stack_b, int b_below)
{
	while ((*stack_a)->index - 1 != 0)
	{
		ft_rotate_a(stack_a);
		(*stack_a)->index -= 1;
	}
	while (b_below != 0)
	{
		ft_reverse_rotate_b(stack_b);
		b_below -= 1;
	}
	ft_push_b (stack_a, stack_b);
	/*printf("lista AAmix1\n");
	print_stack(*stack_a);*/
	return;
}

void move_a_to_b_mix2(t_struct **stack_a, t_struct **stack_b, int a_below)
{
	while (a_below != 0)
	{
		ft_reverse_rotate_a(stack_a);
		a_below -= 1;
	}
	while ((*stack_a)->target_index - 1 != 0)
	{
		ft_rotate_b(stack_b);
		(*stack_a)->target_index -= 1;
	}
	/*printf("lista AAmi2\n");
	print_stack(*stack_a);*/
	ft_push_b (stack_a, stack_b);
	return;
}

void move_a_to_b(t_struct **stack_a, t_struct **stack_b)
{
	int half_b;
	int a_below;
	int b_below;
	t_struct *aux;

	half_b = (ft_structsize(*stack_b) + 1) / 2;
	aux = (*stack_a);
	while (stack_a && *stack_a)
	{
		a_below = ft_structsize(aux) - (*stack_a)->index + 1;
		b_below = ft_structsize(*stack_b) - (*stack_a)->target_index + 1;
		if ((*stack_a)->cheapest == 1)
		{
			if ((*stack_a)->above == 1 && (*stack_a)->target_index <= half_b)
			{
				move_a_to_b_above(stack_a, stack_b);
				return;
			}
			else if ((*stack_a)->above == 0 && (*stack_a)->target_index > half_b)
			{
				move_a_to_b_below(stack_a, stack_b, a_below, b_below);
			printf("State after move_a_to_b:\n");
			printf("// list a\n");
			print_stack(*stack_a);
			printf("// list b\n");
			print_stack(*stack_b);
				return;
			}
			else if ((*stack_a)->above == 1 && (*stack_a)->target_index > half_b)
			{
				move_a_to_b_mix1(stack_a, stack_b, b_below);
				return;
			}
			else if ((*stack_a)->above == 0 && (*stack_a)->target_index <= half_b)
			{
				move_a_to_b_mix2(stack_a, stack_b, a_below);
				return;
			}
		}
		(*stack_a) = (*stack_a)->next;
	}
	//(*stack_a) = aux;
	return;
}

void    sort_algorithm(t_struct **stack_a, t_struct **stack_b)
{
    ft_push_b(stack_a, stack_b);
    if (ft_structsize(*stack_a) > 3)
	{
        ft_push_b(stack_a, stack_b);
	}
	print_stack(*stack_b);
	//ft_push_b(stack_a, stack_b); //para comprobar cheapest con 4 6 2 1 7 3 0 5
	//ft_push_b(stack_a, stack_b);
	while (ft_structsize(*stack_a) > 3)
	{
    	set_stacks(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	printf("// list a\n");
	print_stack(*stack_a);
	printf("// list b\n");
	print_stack(*stack_b);
	}
	printf("list a\n");
	print_stack(*stack_a);
	printf("list b\n");
	print_stack(*stack_b);
	//sort_three(stack_a);
	return;
}

int	main(int argc, char **argv)
{
	t_struct	*stack_a = NULL;
	t_struct	*stack_b = NULL;

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
    //print_stack(stack_a);
	ft_structclear(&stack_a);
	return (0);
}
