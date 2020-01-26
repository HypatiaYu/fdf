/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:18:37 by hyu               #+#    #+#             */
/*   Updated: 2019/09/30 15:08:40 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		length;
	unsigned int		i;
	char				*array;

	i = 0;
	length = ft_strlen(s);
	if (!(array = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	if (length == 0)
		return (0);
	while (i < length)
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
