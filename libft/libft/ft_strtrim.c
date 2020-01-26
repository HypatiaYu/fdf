/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:19:48 by hyu               #+#    #+#             */
/*   Updated: 2019/10/04 16:58:54 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		len_s;
	char		*trim_string;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	len_s = (size_t)ft_strlen(s);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
	}
	while ((s[len_s - j] == ' ' || s[len_s - j] == '\n' ||
			s[len_s - j] == '\t' || s[len_s - j] == '\0') && i + j < len_s)
	{
		j++;
	}
	if (!(trim_string = (char*)malloc((len_s - j - i + 2) * sizeof(char))))
		return (NULL);
	ft_strncpy(trim_string, (s + i), (len_s - j - i + 1));
	trim_string[len_s - j - i + 1] = '\0';
	return (trim_string);
}
