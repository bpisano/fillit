/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_verificication.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:34 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/16 18:23:13 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 ** Check if tetri[x][y] exists and is 1.
 ** Return 1 if it's the case, else 0.
*/

int		check_contact(int **tetri, int x, int y)
{
	if (x >= 0 && x <= 3 && y >= 0 && y <= 3)
		return (tetri[x][y] == 1);
	return (0);
}

/*
 ** Check if the 1 in tetri[x][y] is in contact with another 1.
 ** Return 1 if it's the case, else 0;
*/

int		is_in_contact(int **tetri, int x, int y)
{
	int res;

	res = 0;
	if (!(*tetri))
		return (0);
	if (tetri[x][y] != 1)
		return (0);
	if (x > 3 || y > 3)
		return (0);
	if (check_contact(tetri, x + 1, y) == 1)
		return (1);
	if (check_contact(tetri, x - 1, y) == 1)
		return (1);
	if (check_contact(tetri, x, y + 1) == 1)
		return (1);
	if (check_contact(tetri, x, y - 1) == 1)
		return (1);
	return (0);
}

/*
 ** Check if model is valid.
 ** Return 1 if is valid, else 0.
*/

int		check_model(t_tetri *model)
{
	int		i;
	int		y;
	int		nb_blocks;

	if (!model)
		return (0);
	i = 0;
	nb_blocks = 0;
	while (i < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (model->tetri[i][y] == 1)
			{
				nb_blocks++;
				if (nb_blocks > 4)
					return (0);
				if (is_in_contact(model->tetri, i, y) == 0)
					return (0);
			}
			y++;
		}
	}
	return (1);
}

/*
 ** Check if all models are valid.
 ** Return 1 if all are valid, else 0.
*/

int		model_is_valid(t_tetri **models, int nb_models)
{
	int		i;

	if (!(*models))
		return (0);
	i = 0;
	while (i < nb_models)
	{
		if (check_model(models[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
