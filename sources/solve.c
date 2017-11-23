/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:11:12 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 18:26:31 by bpisano     ###    #+. /#+    ###.fr     */
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

void	print_list(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		print_map(((t_tetri *)(current->content))->tetri);
		printf("\n");
		current = current->next;
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

int		try(t_map *map, int deep)
{
	unsigned int	i;
	int				x;
	int				y;
	t_list			*current_t;

	if (!(map->todo))
		return (1);
	i = 0;
	while ((current_t = ft_lstpopi(&(map->todo), i)))
	{
		y = 0;
		while (y < map->size)
		{
			x = 0;
			while (x < map->size)
			{
				if (put(map, (t_tetri *)current_t->content, x, y))
				{
					printf("DEEP : %d\n", deep);
					print_map(map->map);
					printf("\n");
					if (try(map, deep + 1))
						return (1);
					else
						remove_t(map, (t_tetri *)(current_t->content), x, y);
				}
				if (((t_tetri *)(current_t->content))->width > 1)
					x += ((t_tetri *)(current_t->content))->width - 1;
				else
					x++;
			}
			if (((t_tetri *)(current_t->content))->height > 1)
				y += ((t_tetri *)(current_t->content))->height - 1;
			else
				y++;
		}
		ft_lstaddi(&(map->todo), current_t, i);
		i++;
	}
	return (0);
}

void	solve(t_map *map)
{
	t_list	initial_todo;

	initial_todo = *map->todo;
	while (!try(map, 0))
	{
		printf("\n\n\n\n---------------------------------------\n");
		//print_map(map->map);
		//printf("\n");
		map->todo = &initial_todo;
		map->size++;
		map->map = char_map(map->size);	
	}
	//printf("FINAL\n");
	print_map(map->map);	
}
