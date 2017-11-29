/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   contact.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 12:05:59 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 12:28:14 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		can_put(t_map *map, t_tetri *tetri, int x, int y)
{
	int		o_x;
	int		o_y;
	int		t_x;
	int		t_y;

	if ((tetri->width + x > map->size) || (tetri->height + y > map->size))
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
			if (map->map[y][x] != '.' && tetri->tetri[t_y][t_x] != '.')
				return (0);
			x++;
			t_x++;
		}
		y++;
		t_y++;
	}
	return (1);
}

int		contact(t_map *map, int x, int y, int deep)
{
	if (deep > 4)
		return (0);
	if (x > map->size - 1 || y > map->size - 1 || map->map[y][x] != '.')
		return (1);
	return (1 + (contact(map, x, y + 1, deep + 1) ||
				contact(map, x + 1, y, deep + 1)));
}

int		isolated_blocks(t_map *map, t_tetri *tetri, int x, int y)
{
	int		o_x;
	int		o_y;
	int		count;

	o_x = x;
	o_y = y;
	count = 0;
	while (y - o_y < tetri->height)
	{
		x = o_x - 1;
		while (++x - o_x < tetri->width)
		{
			if (count > 3)
				count = 0;
			if ((x - 1 < 0 && y - 1 < 0) ||
					(y - 1 < 0 && map->map[y][x - 1] != '.') ||
					(x - 1 < 0 && map->map[y - 1][x] != '.'))
			{
				if (map->map[y][x] == '.')
					count += contact(map, x, y, 0);
			}
		}
		y++;
	}
	return (count > 3 ? 0 : count);
}
