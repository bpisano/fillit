/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:42:44 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/13 15:46:09 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **lst, t_list *new)
{
	t_list *iterator;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	iterator = *lst;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = new;
}
