/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:11:39 by hyu               #+#    #+#             */
/*   Updated: 2020/01/29 13:52:08 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
