/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:15:48 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/21 18:19:32 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		smaller_square(t_list **model)
{
	t_list			*current;
	unsigned int		total;

	current = *model;
	while (current)
	{
		total += 4;
		current = current->next;
	}
	return (ft_sqrt(total));
}

static t_map	*map(int size)
{
	t_map	*map;
	char	**map_str;
	int		i;
	int		j;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map_str = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			if (!(map_str[i] = (char *)malloc(sizeof(char) * (size + 1))))
				return (NULL);
			map_str[i][j] = '.';
			j++;
		}
		map_str[i][j] = '\0';
	}
	map_str[i] = NULL;
	map->map = map_str;
	return (map);
}

t_map			*build_map(t_list **model)
{
	t_map	*new_map;
	int		min_square;

	min_square = smaller_square(model);
	new_map = map(min_square);
	new_map->size = min_square;
	return (new_map);
}
