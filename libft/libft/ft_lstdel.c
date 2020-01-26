/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:00:45 by hyu               #+#    #+#             */
/*   Updated: 2019/09/30 14:58:22 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*new_node;

	tmp = *alst;
	while (tmp)
	{
		new_node = tmp->next;
		del((tmp->content), (tmp->content_size));
		free(tmp);
		tmp = new_node;
	}
	*alst = NULL;
}
