/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:40:27 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/22 17:54:28 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **lst, int index)
{
	int		i;
	t_list	*current;
	t_list	*previous;

	if (!*lst)
		return (NULL);
	i = 0;
	current = *lst;
	previous = NULL;
	while (i < index)
	{
		if (!current)
			return (NULL);
		previous = current;
		current = current->next;
		i++;
	}
	if (!previous)
		*lst = current->next;
	else
		previous->next = current->next;
	return (current);
}
