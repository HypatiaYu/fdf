/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:53:08 by hyu               #+#    #+#             */
/*   Updated: 2019/09/20 15:20:28 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t lens1;
	size_t lens2;

	lens1 = 0;
	lens2 = 0;
	while (s1[lens1])
		lens1++;
	while ((s2[lens2]) && (lens2 < n))
	{
		s1[lens1 + lens2] = s2[lens2];
		lens2++;
	}
	s1[lens1 + lens2] = '\0';
	return (s1);
}
