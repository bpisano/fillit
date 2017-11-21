/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjustments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:18:53 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/20 19:42:34 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>
int		width(char **tetri)
{
	int		x;
	int		y;
	int		width;
	int		max_width;

	y = 0;	
	max_width = 0;
	while (tetri[y])
	{
		x = 0;
		width = 0;
		while (tetri[y][x])
		{
			if (tetri[y][x] != '.')
				width++;
			x++;
		}
		if (width > max_width)
			max_width = width;
		y++;
	}
	return (max_width);
}

int		height(char **tetri)
{
	int		x;
	int		y;
	int		height;
	int		max_height;

	x = 0;	
	max_height = 0;
	while (x < 4)
	{
		y = 0;
		height = 0;
		while (y < 4)
		{
			if (tetri[y][x] != '.')
				height++;
			y++;
		}
		if (height > max_height)
			max_height = height;
		x++;
	}
	return (max_height);
}

void	adjust(t_tetri **model)
{
	int		i;

	i = 0;
	while (model[i])
	{
		model[i]->width = width(model[i]->tetri);
		model[i]->height = height(model[i]->tetri);
		printf("%d, %d", model[i]->width, model[i]->height);
		i++;
	}
}