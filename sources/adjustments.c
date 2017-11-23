/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   adjustments.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:08:32 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 12:09:57 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		width(char **tetri)
{
	int		max_x;
	int		min_x;
	int		max_y;
	int		min_y;

	set_max_pos(tetri, &max_x, &max_y);
	set_min_pos(tetri, &min_x, &min_y);
	return (max_y + 1 - min_y);
}

int		height(char **tetri)
{
	int		max_x;
	int		min_x;
	int		max_y;
	int		min_y;

	set_max_pos(tetri, &max_x, &max_y);
	set_min_pos(tetri, &min_x, &min_y);
	return (max_x + 1 - min_x);
}

char	**resize(t_tetri *tetri)
{
	int		min_x;
	int		min_y;
	char	**res;
	int		x;
	int		y;

	if (!tetri)
		return (NULL);
	if (!(res = (char **)ft_memalloc(sizeof(char *) * (tetri->height + 1))))
		return (NULL);
	set_min_pos(tetri->tetri, &min_x, &min_y);
	x = min_x - 1;
	while (++x < min_x + tetri->height)
	{
		res[x - min_x] = (char *)ft_memalloc(sizeof(char) * (tetri->width + 1));
		if (!res[x - min_x])
			return (NULL);
		y = min_y - 1;
		while (++y < min_y + tetri->width)
			res[x - min_x][y - min_y] = tetri->tetri[x][y];
		res[x - min_x][y - min_y] = '\0';
	}
	res[tetri->height] = NULL;
	return (res);
}

void	adjust(t_list **model)
{
	t_list	*iterator;
	t_tetri	*tetri;

	iterator = (*model);
	if (!iterator)
		return ;
	while (iterator)
	{
		tetri = (t_tetri *)iterator->content;
		tetri->width = width(tetri->tetri);
		tetri->height = height(tetri->tetri);
		tetri->tetri = resize(tetri);
		iterator = iterator->next;
	}
}
