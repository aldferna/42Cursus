/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:53:02 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:19:17 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_struct *stack_a)
{
	int	aux;

	if (stack_a->next != NULL)
	{
		aux = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = aux;
	}
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_struct *stack_b)
{
	int	aux;

	if (stack_b->next != NULL)
	{
		aux = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = aux;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(t_struct *stack_a, t_struct *stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	write(1, "ss\n", 3);
}

void	ft_push_a(t_struct **stack_a, t_struct **stack_b)
{
	t_struct	*aux;

	if (*stack_b == NULL)
		return ;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = *stack_a;
	*stack_a = aux;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_struct **stack_a, t_struct **stack_b)
{
	t_struct	*aux;

	if (*stack_a == NULL)
		return ;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = *stack_b;
	*stack_b = aux;
	write(1, "pb\n", 3);
}

/*int main()
{
	t_struct *sta = NULL;
	t_struct *stb = NULL;
	t_struct *node;
	t_struct *node1;
	int i = 1;
	int j = 10;

	while (i < 4)
	{
		node = ft_structnew(i);
		node1 = ft_structnew(j);
		ft_structadd_back(&sta, node);
		ft_structadd_back(&stb, node1);
		i++;
		j += 10;
	}
	//ft_push_b(&sta, &stb);
	//ft_rotate(&sta);
	ft_reverse_rotate(&sta);
	// while (sta != NULL)
	// {
		printf ("stack a: ");
		while (sta != NULL)
		{
			printf("%d ", sta->content);
			sta = sta->next;
		}
		// printf ("stack b: ");
		// while (stb != NULL)
		// {
		//     printf("%d ", stb->content);
		//     stb = stb->next;
		// }
	}
// }*/
