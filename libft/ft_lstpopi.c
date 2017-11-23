/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpopi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:39:29 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 13:08:44 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpopi(t_list **lst, unsigned int index)
{
	unsigned int	i;
	t_list			*current;
	t_list			*previous;

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
