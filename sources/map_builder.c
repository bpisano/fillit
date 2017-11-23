/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_builder.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:12:31 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 14:16:09 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		smaller_square(t_list **model)
{
	t_list			*current;
	unsigned int		total;

	current = *model;
	total = 0;
	while (current)
	{
		total += 4;
		current = current->next;
	}
	return (ft_sqrt(total));
}

char			**char_map(int size)
{
	char	**map_str;
	int		i;
	int		j;
	
	if (!(map_str = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = 0;
		if (!(map_str[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (j < size)
		{	
			map_str[i][j] = '.';
			j++;
		}
		map_str[i][j] = '\0';
	}
	map_str[i] = NULL;
	return (map_str);
}

t_map			*build_map(t_list **model)
{
	t_map	*new_map;
	int		min_square;

	if (!(new_map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	min_square = smaller_square(model);
	new_map->map = char_map(min_square);
	new_map->size = min_square;
	new_map->todo = *model;
	return (new_map);
}
