/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:23:34 by hyu               #+#    #+#             */
/*   Updated: 2019/10/04 10:26:36 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len_dst;
	size_t len_src;
	size_t i;

	len_dst = ft_strlen((char*)dst);
	len_src = ft_strlen((char*)src);
	i = 0;
	if (dstsize == 0)
		return (len_src);
	if (dstsize < len_dst + 1)
		return (dstsize + len_src);
	if (dstsize > len_dst)
	{
		while (i + len_dst < dstsize - 1)
		{
			dst[i + len_dst] = src[i];
			i++;
		}
		dst[i + len_dst] = '\0';
	}
	return (len_src + len_dst);
}
