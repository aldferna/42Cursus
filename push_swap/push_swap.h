/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:58:24 by aldferna          #+#    #+#             */
/*   Updated: 2024/11/05 15:54:42 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_struct
{
	int				content;
	struct t_struct	*next;
}					t_struct;

void				check_notchar_arg(char *str);
char				*join_args(int argc, char **argv);
t_struct			*ft_structnew(int content);
t_struct			*ft_structlast(t_struct *lst);
void				ft_structadd_back(t_struct **lst, t_struct *new);
//void				ft_structiter(t_struct *lst, void (*f)(int));
void				ft_structclear(t_struct **lst);
int					ft_atoi_limit(const char *nptr);

void				print_error(char *str);

#endif
