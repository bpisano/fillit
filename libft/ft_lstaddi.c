/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstaddi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:57:01 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:12:34 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddi(t_list **lst, t_list *new, unsigned int index)
{
	t_list			*iterator;
	t_list			*previous;
	unsigned int	i;

	if (!new || (!(*lst) && index != 0))
		return ;
	iterator = *lst;
	previous = NULL;
	i = 0;
	while (i < index)
	{
		if (!iterator)
			return ;
		previous = iterator;
		iterator = iterator->next;
		i++;
	}
	if (!(*lst))
		*lst = new;
	else if (index == 0)
	{
		*lst = new;
		new->next = iterator;
	}
	else
	{
		previous->next = new;
		new->next = iterator;
	}
}
