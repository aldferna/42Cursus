/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:31:52 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:18:17 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_struct **stack_a, int ok)
{
	t_struct	*head;
	t_struct	*last;

	head = *stack_a;
	last = ft_structlast(*stack_a);
	last->next = head;
	*stack_a = (*stack_a)->next;
	head->next = NULL;
	if (ok == 1)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_struct **stack_b, int ok)
{
	t_struct	*head;
	t_struct	*last;

	head = *stack_b;
	last = ft_structlast(*stack_b);
	last->next = head;
	*stack_b = (*stack_b)->next;
	head->next = NULL;
	if (ok == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_struct **stack_a, t_struct **stack_b)
{
	ft_rotate_a(stack_a, 0);
	ft_rotate_b(stack_b, 0);
	write(1, "rr\n", 3);
}
