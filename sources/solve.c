/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:11:12 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 14:18:06 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_map(char **map)
{
	int		i;
	
	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

int		out_of_bounds(t_map *map, t_tetri *tetri, int x, int y)
{
	if (tetri->width + x > map->size)
		return (1);
	if (tetri->height + y > map->size)
		return (1);
	return (0);
}

int		can_put(t_map *map, t_tetri *tetri, int x, int y)
{
	int		o_x;
	int		o_y;
	int		t_x;
	int		t_y;

	if (out_of_bounds(map, tetri, x, y))
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
			map->map[y][x] = tetri->tetri[t_y][t_x];
			x++;
			t_x++;
		}
		y++;
		t_y++;
	}
	return (1);
}

int		try(t_map *map)
{
	unsigned int	i;
	int				x;
	int				y;
	t_list			*todo;
	t_list			*current_t;

	if (!(todo = map->todo))
		return (1);
	i = 0;
	while ((current_t = ft_lstat(&todo, i)))
	{
		y = 0;
		while (y < map->size)
		{
			x = 0;
			while (x < map->size)
			{
				if (put(map, (t_tetri *)current_t->content, x, y))
				{
					ft_lstpopi(&map->todo, i);
					return(try(map));
				}
				x++;
			}
			y++;
		}
		i++;
	}
	return (0);
}

void	solve(t_map *map)
{
	t_list	initial_todo;

	initial_todo = *map->todo;
	while (!try(map))
	{
		//print_map(map->map);
		//printf("\n");
		map->todo = &initial_todo;
		map->size++;
		map->map = char_map(map->size);	
	}
	print_map(map->map);	
}
