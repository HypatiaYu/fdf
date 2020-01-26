/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:28:46 by hyu               #+#    #+#             */
/*   Updated: 2019/10/05 21:16:30 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				i;

	i = 0;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	if (dest > source)
	{
		while ((int)(len--))
			*(dest + len) = *(source + len);
	}
	else
	{
		while (i < len)
		{
			*(dest + i) = *(source + i);
			i++;
		}
	}
	return ((void*)dest);
}
