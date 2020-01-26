/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:16:53 by hyu               #+#    #+#             */
/*   Updated: 2019/10/06 21:47:08 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *hay, const char *ndl)
{
	int		hay_count;
	int		ndl_count;
	int		start;
	char	*hay_ret;

	hay_count = 0;
	ndl_count = 0;
	hay_ret = (char*)hay;
	if (!(*ndl))
		return (hay_ret);
	start = ft_start(hay, ndl);
	while (hay[start])
	{
		if (ft_strncmp((hay + start), ndl, ft_strlen(ndl)) == 0)
			return (hay_ret + start);
		else
		{
			start++;
			while ((hay[start] && hay[start] != ndl[0]))
				start++;
		}
	}
	return (NULL);
}
