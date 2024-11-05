/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:54:28 by aldferna          #+#    #+#             */
/*   Updated: 2024/11/05 17:42:57 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack_a(t_struct **stack_a, char **args)
{
    t_struct *node;
    int i;

    i = 0;
    while (args[i])
    {
        node = ft_structnew((ft_atoi_limit(args[i])));
        ft_structadd_back(stack_a, node);
        i++;
    }
}

void print_stack(t_struct *stack_a)
{
    while (stack_a != NULL)
    {
        printf("%d\n", stack_a -> content);
        stack_a = stack_a -> next;
    }
}

void repeat_num(t_struct *stack_a)
{
    int num;
    t_struct *head;

    head = stack_a;
    while (head != NULL)
    {
        num = head->content;
        head = head->next;
        stack_a = head;
        while (stack_a != NULL)
        {
            if(num == stack_a -> content)
                print_error("There are repeated numbers.");
            stack_a = stack_a -> next;
        }
    }
}

int main(int argc, char **argv)
{
    char *str;
    char **args;
    int i;
    t_struct *stack_a = NULL;
    
    if (argc < 2)
        return (1);
    
    str = join_args(argc, argv);
    check_notchar_arg(str);
    args = ft_split(str, ' ');
    free (str);
    fill_stack_a(&stack_a, args);
    i = 0;
    while(args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
    repeat_num(stack_a);
    print_stack(stack_a);
    ft_structclear(&stack_a);
    return (0);
}
