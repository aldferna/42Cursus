/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_struct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:14:02 by aldferna          #+#    #+#             */
/*   Updated: 2024/11/05 15:54:32 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_structnew(int content)
{
	t_struct	*new_node;

	new_node = (t_struct *)malloc(sizeof(t_struct));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_struct	*ft_structlast(t_struct *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_structadd_back(t_struct **lst, t_struct *new)
{
	t_struct	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_structlast(*lst);
		last->next = new;
	}
}


// void	ft_structiter(t_struct *lst, void (*f)(int))
// {
// 	while (lst != NULL)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// }

void	ft_structclear(t_struct **lst)
{
	t_struct	*temp;

	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
