/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:29:25 by aldferna          #+#    #+#             */
/*   Updated: 2024/11/05 12:15:06 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *join_args(int argc, char **argv)
{
    char *str = ft_calloc(1, sizeof(char));
    char *aux;
    int i;
    
    i = 1;
    while (i < argc)
    {
        aux = ft_strjoin(str, " ");
        free (str);
        str = ft_strjoin(aux, argv[i]);
        free (aux);
        i++;
    }
    return (str);
}

void check_notchar_arg (char *str)
{
    int i;

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
        //printf("argv[%d] = %s\n", i, argv[i]);    
    }
}
