/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:04:10 by hyu               #+#    #+#             */
/*   Updated: 2019/09/28 18:33:29 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str_ret;

	if (!(str_ret = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str_ret, (int)'\0', size + 1);
	return (str_ret);
}
