/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:32:34 by hyu               #+#    #+#             */
/*   Updated: 2019/09/23 11:14:48 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	lens1;
	int lens2;

	lens1 = ft_strlen(s1);
	lens2 = 0;
	while (s2[lens2])
	{
		s1[lens1 + lens2] = s2[lens2];
		lens2++;
	}
	s1[lens1 + lens2] = '\0';
	return (s1);
}
