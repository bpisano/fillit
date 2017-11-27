/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:11:12 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 20:11:03 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>
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

int		contact(t_map *map, int x, int y, int deep)
{
	if (deep > 4)
		return (0);
	if (x > map->size - 1 || y > map->size - 1 || map->map[y][x] != '.')
		return (1);
	return (1 + (contact(map, x, y + 1, deep + 1) || contact(map, x + 1, y, deep + 1)));
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
		x = o_x;
		while (x - o_x < tetri->width)
		{
			
			if (count > 3)
				count = 0;
			if ((x - 1 < 0 && y - 1 < 0) || (y - 1 < 0 && map->map[y][x - 1] != '.') || (x - 1 < 0 && map->map[y - 1][x] != '.'))
			{
				if (map->map[y][x] == '.')
				{	
					count += contact(map, x, y, 0);
					//printf("Count : %d, %d, %d\n", count, x, y);
				}
			}
			x++;
		}
		y++;
	}
	return (count > 3 ? 0 : count);
}

int		try(t_map *map)
{
	int				x;
	int				y;
	int				isolated;
	t_list			*current_t;

	if (!(map->todo))
		return (1);	
	if (ft_lstlen(map->todo) * 4 > map->area || !(current_t = ft_lstpopi(&(map->todo), 0)))
	{
		return (0);
	}
	y = -1;
	while (++y < map->size)
	{
		x = -1;
		while (++x < map->size)
		{
			if (put(map, (t_tetri *)current_t->content, x, y))
			{
				//printf("\n\n");
				//printf("MAP\n");
				//print_map(map->map);
				isolated = isolated_blocks(map, (t_tetri *)(current_t->content), x, y);
				map->area -= (isolated + 4);		
				//printf("Isolated : %d\n", isolated);
				//printf("Area : %d\n", map->area);
				//printf("Estimated todo area : %d\n", ft_lstlen(map->todo) * 4);
				//sleep(1);
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
		map->size++;
		map->area = map->size * map->size;
		free_dual_strings(map->map);
		map->map = char_map(map->size);
	}
	print_map(map->map);
}
