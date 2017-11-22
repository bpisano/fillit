/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:37:56 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/22 19:23:51 by bpisano          ###   ########.fr       */
/*                                                                            */
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

int		can_put(t_map *map, t_tetri *tetri, int x, int y)
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
	int		i;
	int		x;
	int		y;
	t_list	*todo;
	t_list	*current_t;

	if (!(todo = map->todo))
		return (1);
	i = 0;
	while ((current_t = ft_lstpop(&todo, i)))
	{
		y = 0;
		while (y < map->size)
		{
			x = 0;
			while (x < map->size)
			{
				if (put(map, (t_tetri *)current_t->content, x, y))
				{
					ft_lstadd(&map->placed, current_t);
					return(try(map));
				}
				x++;
				// Remmettre au bon index
			}
			y++;
		}
		i++;
	}
	return (0);
}

void	solve(t_map *map)
{
	put(map, (t_tetri *)((map->todo)->content), 0, 0);
	ft_lstpop(&map->todo, 0);
	put(map, (t_tetri *)((map->todo)->content), 1, 0);
	print_map(map->map);
}
