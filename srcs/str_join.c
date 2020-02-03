/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:00:28 by hyu               #+#    #+#             */
/*   Updated: 2020/01/31 21:20:04 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		*ft_strjoina(char *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*joined;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(joined = (char*)malloc((lens1 + lens2 + 1) * sizeof(char*))))
		return (NULL);
	while (i < lens1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < lens2)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}

char		*ft_strjoinb(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*joined;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = -1;
	j = -1;
	if (!(joined = (char*)malloc((lens1 + lens2 + 1) * sizeof(char*))))
		return (NULL);
	while (++i < lens1)
	{
		joined[i] = s1[i];
	}
	while (++j < lens2)
	{
		joined[i + j] = s2[j];
	}
	joined[i + j] = '\0';
	free(s1);
	free(s2);
	return (joined);
}
