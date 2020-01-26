/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:35:32 by hyu               #+#    #+#             */
/*   Updated: 2019/10/02 19:46:19 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*str;

	str = (char *)s;
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == c)
			return (str + length);
		length--;
	}
	return (NULL);
}
