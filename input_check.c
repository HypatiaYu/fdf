/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:02:35 by hyu               #+#    #+#             */
/*   Updated: 2020/01/16 14:47:06 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"


void    ft_space(char *str, int *i, int *j)
{
    while (str[*i] != '\0' && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'))
    {
        if (str[*i] == '\n')
        {
            ft_putnbr(*j);
            *j = *j + 1;
        }
    *i = *i + 1;
    }
}

void    ft_word(char *str, int *i, int *k)
{
    while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n')
        *i = *i + 1;
    *k = *k + 1;
}

/*int		ft_ishex(char *str, int *i)
{
	if (str[*i] == ',' && str[*i + 1] == '0' && str[*i + 2] == 'x')
	   return (1);
	return (0);	
}*/

int     ft_word_check(char *str, int *i, int *k, t_point *dimensions, int *j)
{
    int j_initial;
    int initial;

    initial = *k;
    j_initial = *j;
    while (str[*i] != '\0' && *j < j_initial + 1)
    {
        ft_word(str, i, k);
        ft_space(str, i, j);
    }
    if (*k - initial == dimensions->x)
        return (1);
    else
        return (0);
}

