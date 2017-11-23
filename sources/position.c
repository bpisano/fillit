/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   position.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:10:56 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 12:10:59 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	set_min_pos(char **tetri, int *min_x, int *min_y)
{
	int x;
	int y;

	*min_x = 3;
	*min_y = 3;
	if (!tetri)
		return ;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetri[x][y] != '.')
			{
				if (x < (*min_x))
					*min_x = x;
				if (y < (*min_y))
					*min_y = y;
			}
			y++;
		}
		x++;
	}
}

void	set_max_pos(char **tetri, int *max_x, int *max_y)
{
	int x;
	int y;

	*max_x = 0;
	*max_y = 0;
	if (!tetri)
		return ;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetri[x][y] != '.')
			{
				if (x > (*max_x))
					*max_x = x;
				if (y > (*max_y))
					*max_y = y;
			}
			y++;
		}
		x++;
	}
}
