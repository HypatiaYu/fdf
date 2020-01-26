/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:18:39 by hyu               #+#    #+#             */
/*   Updated: 2020/01/11 12:18:23 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		j;
	int		k;
	char	**out;

	j = 0;
	k = 0;
	if (!s || !(out = (char**)malloc(sizeof(char*) * (ft_w_ct(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(out[j] = (char*)malloc(sizeof(char) * (ft_wlen((s), c) + 1))))
				return (NULL);
			while (*s && *s != c)
				out[j][k++] = (char)*s++;
			out[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	out[j] = 0;
	return (out);
}
