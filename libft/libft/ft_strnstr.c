/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:10:31 by hyu               #+#    #+#             */
/*   Updated: 2019/10/07 11:41:43 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t		start;
	size_t		ndl_index;
	char		*hay_ret;

	start = 0;
	hay_ret = (char*)hay;
	if (!(*ndl))
		return ((char *)hay_ret);
	if (ft_strcmp(hay, "") == 0 || len == 0)
		return (NULL);
	while ((hay_ret[start]) && (start < len))
	{
		ndl_index = 0;
		while ((hay_ret[start + ndl_index] == ndl[ndl_index]) &&
				((start + ndl_index) < len))
		{
			ndl_index++;
			if ((ndl[ndl_index] == '\0'))
				return (hay_ret + start);
		}
		start++;
	}
	return (NULL);
}
