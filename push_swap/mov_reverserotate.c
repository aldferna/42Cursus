/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_reverserotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:59:12 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:17:17 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_struct **stack_a, int ok)
{
	t_struct	*last;
	t_struct	*pre_last;
	t_struct	*aux;

	pre_last = NULL;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = ft_structlast(*stack_a);
	aux = *stack_a;
	while (aux->next != NULL)
	{
		pre_last = aux;
		aux = aux->next;
	}
	if (pre_last)
	{
		pre_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if (ok == 1)
		write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_struct **stack_b, int ok)
{
	t_struct	*last;
	t_struct	*pre_last;
	t_struct	*aux;

	pre_last = NULL;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = ft_structlast(*stack_b);
	aux = *stack_b;
	while (aux->next != NULL)
	{
		pre_last = aux;
		aux = aux->next;
	}
	if (pre_last)
	{
		pre_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
	if (ok == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_struct **stack_a, t_struct **stack_b)
{
	ft_reverse_rotate_a(stack_a, 0);
	ft_reverse_rotate_b(stack_b, 0);
	write(1, "rrr\n", 4);
}
