/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:29:25 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:23:17 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(int argc, char **argv)
{
	char	*str;
	char	*aux;
	int		i;

	str = ft_calloc(1, sizeof(char));
	i = 1;
	while (i < argc)
	{
		aux = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(aux, argv[i]);
		free(aux);
		i++;
	}
	return (str);
}

void	check_notchar_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == '+' || str[i] == '-' || str[i] == ' ')
			i++;
		else
		{
			write(2, "Error\n", 7);
			exit(2);
		}
	}
}

void	check_repeat_num(t_struct *stack_a)
{
	int			num;
	t_struct	*head;

	head = stack_a;
	while (head != NULL)
	{
		num = head->content;
		head = head->next;
		stack_a = head;
		while (stack_a != NULL)
		{
			if (num == stack_a->content)
				print_error("There are repeated numbers.\n"); // error\n
			stack_a = stack_a->next;
		}
	}
}

/*void	print_stack(t_struct *stack_a)
{
	while (stack_a != NULL)
	{
		dprintf(2, "C: %3d IDX: %2d TG: %2d AB: %d COST: %2d CHEAP: %d\n",
			stack_a->content, stack_a->index, stack_a->target_index,
			stack_a->above, stack_a->push_cost, stack_a->cheapest);
		stack_a = stack_a->next;
	}
}*/

void	fill_stack_a(t_struct **stack_a, char **args)
{
	t_struct	*node;
	int			i;

	i = 0;
	while (args[i])
	{
		node = ft_structnew((ft_atoi_limit(args[i])));
		if (!node)
			ft_structclear(stack_a);
		ft_structadd_back(stack_a, node);
		i++;
	}
}

t_struct	*parsing(int argc, char **argv)
{
	char *str;
	char **args;
	int i;
	t_struct *stack_a = NULL;

	str = join_args(argc, argv);
	check_notchar_arg(str);
	args = ft_split(str, ' ');
	free(str);
	fill_stack_a(&stack_a, args);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	check_repeat_num(stack_a);
	return (stack_a);
}
