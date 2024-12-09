/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_struct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:14:02 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/05 17:43:11 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_structnew(int content)
{
	t_struct	*new_node;

	new_node = ft_calloc(1, sizeof(t_struct));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->target_index = -5;
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

int	ft_structsize(t_struct *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
