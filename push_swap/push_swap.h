/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:58:24 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:12:17 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h> //free malloc
# include <unistd.h> //write

typedef struct t_struct
{
	int				content;
	int				index;
	int				target_index;
	int				above;
	int				push_cost;
	int				cheapest;
	struct t_struct	*next;
}					t_struct;

void				sort_algorithm(t_struct **stack_a, t_struct **stack_b);
void				sort_three(t_struct **stack_a);
int					stack_sorted(t_struct *stack_a);

void				set_stacks(t_struct *stack_a, t_struct *stack_b);
void				put_index(t_struct *stack);
void				search_target_in_b(t_struct *stack_a, t_struct *stack_b);
void				search_target_in_a(t_struct *stack_a, t_struct *stack_b);
void				set_cost(t_struct *stack_a, t_struct *stack_b);
void				set_cheapest(t_struct *stack_a);
int					find_max(t_struct *stack);
int					find_min(t_struct *stack);

void				move_a_to_b(t_struct **stack_a, t_struct **stack_b);
void				move_a_to_b_above(t_struct **stack_a, t_struct **stack_b,
						int a_above, int b_above, char name);
void				move_a_to_b_below(t_struct **stack_a, t_struct **stack_b,
						int a_below, int b_below, char name);
void				move_a_to_b_mix1(t_struct **stack_a, t_struct **stack_b,
						int a_above, int b_below, char name);
void				move_a_to_b_mix2(t_struct **stack_a, t_struct **stack_b,
						int a_below, int b_above, char name);
void				move_b_to_a(t_struct **stack_a, t_struct **stack_b);
void				move_b_to_a_mix1(t_struct **stack_a, t_struct **stack_b,
						int a_below, int b_above, char name);
void				min_on_top(t_struct **stack_a);

t_struct			*parsing(int argc, char **argv);
void				check_notchar_arg(char *str);
int					ft_atoi_limit(const char *nptr);
char				*join_args(int argc, char **argv);

t_struct			*ft_structnew(int content);
t_struct			*ft_structlast(t_struct *lst);
void				ft_structadd_back(t_struct **lst, t_struct *new);
void				ft_structclear(t_struct **lst);
int					ft_structsize(t_struct *lst);

void				ft_swap_a(t_struct *stack_a);
void				ft_swap_b(t_struct *stack_b);
void				ft_ss(t_struct *stack_a, t_struct *stack_b);
void				ft_push_a(t_struct **stack_a, t_struct **stack_b);
void				ft_push_b(t_struct **stack_a, t_struct **stack_b);
void				ft_rotate_a(t_struct **stack_a, int ok);
void				ft_rotate_b(t_struct **stack_b, int ok);
void				ft_rr(t_struct **stack_a, t_struct **stack_b);
void				ft_reverse_rotate_a(t_struct **stack_a, int ok);
void				ft_reverse_rotate_b(t_struct **stack_b, int ok);
void				ft_rrr(t_struct **stack_a, t_struct **stack_b);

void				print_error(char *str);
void				print_stack(t_struct *stack_a);

#endif
