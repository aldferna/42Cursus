/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_reverserotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:59:12 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/04 20:03:24 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate_a(t_struct **stack_a)
{
    t_struct *last;
    t_struct *pre_last = NULL;
    t_struct *aux;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    last = ft_structlast(*stack_a);
    aux = *stack_a;
    while(aux->next != NULL)
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
    write(1, "rra\n", 4);
}

void ft_reverse_rotate_b(t_struct **stack_b)
{
    t_struct *last;
    t_struct *pre_last = NULL;
    t_struct *aux;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;

    last = ft_structlast(*stack_b);
    aux = *stack_b;
    while(aux->next != NULL)
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
    write(1, "rrb\n", 4);
}

void ft_rrr(t_struct **stack_a, t_struct **stack_b)
{
    ft_reverse_rotate_a(stack_a);
    ft_reverse_rotate_b(stack_b);
    write(1, "rrr\n", 4);
}
