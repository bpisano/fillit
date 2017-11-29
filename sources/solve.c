/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:11:12 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 13:53:15 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		try(t_map *map)
{
	int		x;
	int		y;
	t_list	*current_t;

	if (!(map->todo))
		return (1);
	if (ft_lstlen(map->todo) * 4 > map->area ||
			!(current_t = ft_lstpopi(&(map->todo), 0)))
		return (0);
	y = -1;
	while (++y < map->size)
	{
		x = -1;
		while (++x < map->size)
		{
			if (try_put(map, current_t, x, y))
				return (1);
		}
	}
	ft_lstadd(&(map->todo), current_t);
	return (0);
}

void	solve(t_map *map)
{
	while (!try(map))
	{
		map->size++;
		map->area = map->size * map->size;
		free_dual_strings(map->map);
		map->map = char_map(map->size);
	}
	print_map(map->map);
}
