/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:11:12 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 14:58:22 by bpisano     ###    #+. /#+    ###.fr     */
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

int		contact(t_map *map, int x, int y)
{
	int		t_x;
	int		t_y;
	int		abs;

	t_y = y - 1;
	while (t_y <= y + 1)
	{
		t_x = x - 1;
		while (t_x <= x + 1)
		{
			abs = x - y < 0 ? -(x - y) : x - y;
			if (abs == 1 && t_x - 1 >= 0 && t_y - 1 >= 0)
			{
				if (map->map[t_y][t_x] == '.')
					return (1);
			}
			t_x++;
		}
		t_y++;
	}
	return (0);
}

int		isolated_blocks(t_map *map, t_tetri *tetri, int x, int y)
{
	int		o_x;
	int		o_y;
	int		t_x;
	int		t_y;
	int		count;

	o_x = x;
	o_y = y;
	t_y = 0;
	count = 0;
	while (y < o_y + tetri->height)
	{
		x = o_x;
		t_x = 0;
		while (x < o_x + tetri->width)
		{
			if (!contact(map, x, y) && map->map[y][x] == '.')
				count++;
			x++;
			t_x++;
		}
		y++;
		t_y++;
	}
	return (count);
}

int		try(t_map *map)
{
	int				x;
	int				y;
	int				isolated;
	t_list			*current_t;

	if (!(map->todo))
		return (1);
	printf("\n%d, %d\n", ft_lstlen(map->todo) * 4, map->area);
	if (!(current_t = ft_lstpopi(&(map->todo), 0)) || ft_lstlen(map->todo) * 4 > map->area)
		return (0);
	y = -1;
	while (++y < map->size)
	{
		x = -1;
		while (++x < map->size)
		{
			if (put(map, (t_tetri *)current_t->content, x, y))
			{
				//print_map(map->map);
				//sleep(1);
				isolated = isolated_blocks(map, (t_tetri *)(current_t->content), x, y);
				map->area -= isolated + 4;
				//printf("ok\n");
				if (try(map))
					return (1);
				else
				{
					map->area += isolated + 4;
					remove_t(map, (t_tetri *)(current_t->content), x, y);
				}
			}
		}
	}
	ft_lstadd(&(map->todo), current_t);
	return (0);
}

void	solve(t_map *map)
{
	while (!try(map))
	{
		//printf("resize\n");
		map->size++;
		free_dual_strings(map->map);
		map->map = char_map(map->size);
	}
	print_map(map->map);
}
