/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:15:48 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/21 17:26:02 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		smaller_square(t_list **model)
{
	t_list			*current;
	t_tetri			*tetri;
	unsigned int	width_sum;
	unsigned int	height_sum;
	unsigned int	max;

	current = *model;
	width_sum = 0;
	height_sum = 0;
	while (current)
	{
		tetri = current->content;
		width_sum += (unsigned int)(tetri->width);
		height_sum += (unsigned int)(tetri->height);
		current = current->next;
	}
	max = width_sum > height_sum ? width_sum : height_sum;
	return (ft_sqrt(max));
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
	i = 0;
	while (i < size)
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
		i++;
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
