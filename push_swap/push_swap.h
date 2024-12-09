/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:58:24 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/09 16:46:10 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h> //free malloc
# include <unistd.h> //write
# include <limits.h>

typedef struct t_struct
{
	int				content;
	int				index;
	int				target_index;
	int				above; //1 si 0 no
	int				push_cost;
	int				cheapest;
	struct t_struct	*next;
}					t_struct;

void sort_algorithm(t_struct **stack_a, t_struct **stack_b);
void	sort_three(t_struct **stack_a);
int	stack_sorted(t_struct *stack_a);

void set_stacks(t_struct *stack_a, t_struct *stack_b);
void put_index(t_struct *stack);
void	search_target(t_struct *stack_a, t_struct *stack_b);
void    set_cost(t_struct *stack_a, t_struct *stack_b);
void set_cheapest(t_struct *stack_a);
int find_max(t_struct *stack);
int find_min(t_struct *stack);

t_struct *parsing(int argc, char **argv);
void				check_notchar_arg(char *str);
int					ft_atoi_limit(const char *nptr);
char				*join_args(int argc, char **argv);

t_struct			*ft_structnew(int content);
t_struct			*ft_structlast(t_struct *lst);
void				ft_structadd_back(t_struct **lst, t_struct *new);
void				ft_structclear(t_struct **lst);
int	ft_structsize(t_struct *lst);

void				ft_swap_a(t_struct *stack_a);
void				ft_swap_b(t_struct *stack_b);
void ft_ss(t_struct *stack_a, t_struct *stack_b);
void ft_push_a(t_struct **stack_a, t_struct **stack_b);
void				ft_push_b(t_struct **stack_a, t_struct **stack_b);
void				ft_rotate_a(t_struct **stack_a);
void ft_rotate_b(t_struct **stack_b);
void ft_rr(t_struct **stack_a, t_struct **stack_b);
void				ft_reverse_rotate_a(t_struct **stack_a);
void ft_reverse_rotate_b(t_struct **stack_b);
void ft_rrr(t_struct **stack_a, t_struct **stack_b);

void				print_error(char *str);
void print_stack(t_struct *stack_a);

#endif
