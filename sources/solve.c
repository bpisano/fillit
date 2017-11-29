/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:11:12 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:28:28 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		put(t_map *map, t_tetri *tetri, int x, int y)
{
	int		o_x;
	int		o_y;
	int		t_x;
	int		t_y;

	if (!can_put(map, tetri, x, y))
		return (0);
	o_x = x;
	o_y = y;
	t_y = 0;
	while (y < o_y + tetri->height)
	{
		x = o_x;
		t_x = 0;
		while (x < o_x + tetri->width)
		{
			if (tetri->tetri[t_y][t_x] != '.')
				map->map[y][x] = tetri->tetri[t_y][t_x];
			x++;
			t_x++;
		}
		y++;
		t_y++;
	}
	return (1);
}

void	remove_t(t_map *map, t_tetri *tetri, int x, int y)
{
	int		o_x;
	int		o_y;
	int		t_x;
	int		t_y;

	o_x = x;
	o_y = y;
	t_y = 0;
	while (y < o_y + tetri->height)
	{
		x = o_x;
		t_x = 0;
		while (x < o_x + tetri->width)
		{
			if (tetri->tetri[t_y][t_x] != '.')
				map->map[y][x] = '.';
			x++;
			t_x++;
		}
		y++;
		t_y++;
	}
}

int		try_put(t_map *map, t_list *current_t, int x, int y)
{
	int		isolated;

	if (!put(map, (t_tetri *)current_t->content, x, y))
		return (0);
	isolated = isolated_blocks(map, (t_tetri *)(current_t->content),
			x, y);
	map->area -= (isolated + 4);
	if (try(map))
		return (1);
	map->area += isolated + 4;
	remove_t(map, (t_tetri *)(current_t->content), x, y);
	return (0);
}

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
