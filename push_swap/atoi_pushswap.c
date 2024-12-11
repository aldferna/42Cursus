/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:00:48 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:16:29 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_space(int *i, const char *nptr)
{
	while (nptr[*i] != '\0' && (nptr[*i] == ' ' || nptr[*i] == '\n'
			|| nptr[*i] == '\t' || nptr[*i] == '\f' || nptr[*i] == '\v'
			|| nptr[*i] == '\r'))
		(*i)++;
}

static int	is_sign(int *i, const char *nptr)
{
	int	sign;

	sign = 1;
	if (nptr[*i] != '\0' && (nptr[*i] == '-' || nptr[*i] == '+'))
	{
		if (nptr[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	if (nptr[*i] != '\0' && (nptr[*i] == '-' || nptr[*i] == '+'))
		exit(5);
	return (sign);
}

int	ft_atoi_limit(const char *nptr)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	if (ft_strlen(nptr) > 11)
		exit(4);
	is_space(&i, nptr);
	sign = is_sign(&i, nptr);
	number = 0;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	number *= sign;
	if (number > 2147483647 || number < -2147483648)
		exit(6);
	return ((int)number);
}
