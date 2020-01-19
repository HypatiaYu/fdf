/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:11:39 by hyu               #+#    #+#             */
/*   Updated: 2020/01/11 12:11:21 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	int			l1;
	int			l2;
	int			i;
	int			j;
	char		*joined;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!s1 || !s2 || !(joined = (char*)malloc((l1 + l2 + 1) * sizeof(char*))))
		return (NULL);
	while (i < l1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < l2)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

char			*ft_copy(char *dst, char *src)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while ((src[i] != '\n') && src[i])
		i++;
	dst = (char*)malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char			*ft_afterspace(char *str)
{
	char		*temp;

	if (!*str)
		return (0);
	temp = ft_strchr(str, '\n');
	if (temp)
		ft_memmove(str, temp + 1, ft_strlen(temp));
	return (str);
}

int				ft_return_line(char **str, char **line, int fd)
{
	if (ft_strchr(str[fd], '\n') != '\0')
	{
		*line = ft_copy(*line, str[fd]);
		ft_afterspace(str[fd]);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	static char	*str[MAX_FD];
	int			len;

	if (BUFF_SIZE <= 0 || fd < 0 || fd >= MAX_FD || line == NULL)
		return (-1);
	while ((len = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[len] = '\0';
		if (!(str[fd]))
			str[fd] = ft_strdup(buffer);
		else if (str[fd])
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
	}
	if (len < 0)
		return (-1);
	if (len == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_return_line(str, line, fd));
}
