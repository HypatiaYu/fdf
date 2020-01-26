/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:16:22 by hyu               #+#    #+#             */
/*   Updated: 2019/09/28 11:39:44 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out1;
	size_t	i;

	i = 0;
	if (!(out1 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && (i < len))
	{
		out1[i] = s[start];
		i++;
		start++;
	}
	out1[i] = '\0';
	return (out1);
}
