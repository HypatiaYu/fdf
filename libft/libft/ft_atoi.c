/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:27:59 by hyu               #+#    #+#             */
/*   Updated: 2019/10/04 16:55:24 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int						sign;
	unsigned long long int	j;
	unsigned long long int	up_bound;

	sign = 1;
	j = 0;
	up_bound = 9223372036854775807;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
				*str == '\v' || *str == '\r' || *str == '\f'))
		++str;
	if (*str == '\0')
		return (0);
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		++str;
	while ((*str <= '9') && (*str >= '0'))
	{
		j = j * 10 + *str - '0';
		++str;
	}
	if (j > up_bound)
		return ((sign < 0) ? 0 : -1);
	return (j * sign);
}
