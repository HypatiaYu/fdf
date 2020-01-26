/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 10:43:57 by hyu               #+#    #+#             */
/*   Updated: 2019/10/02 17:46:26 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	unsigned char	*dest;
	unsigned char	*sorc;
	size_t			i;

	i = 0;
	dest = (unsigned char*)dst;
	sorc = (unsigned char*)src;
	c = (unsigned char)c;
	while (i < n)
	{
		dest[i] = sorc[i];
		if (sorc[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
