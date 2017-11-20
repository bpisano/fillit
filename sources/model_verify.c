/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:34 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/20 17:15:04 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 ** Check if tetri[x][y] exists and is a block.
 ** Return 1 if it's the case, else 0.
*/

static int	check_contact(char **tetri, int x, int y)
{
	if (x >= 0 && x < 4 && y >= 0 && y < 4)
		return (tetri[x][y] != '.');
	return (0);
}

/*
 ** Calculate the number of contact of one block.
 ** Return the number of contact
*/

static int	block_contact(char **tetri, int x, int y)
{
	int		contact;

	contact = 0;
	if (!(*tetri))
		return (0);
	if (tetri[x][y] == '.')
		return (0);
	if (x >= 4 || y >= 4)
		return (0);
	if (check_contact(tetri, x + 1, y))
		contact++;
	if (check_contact(tetri, x - 1, y))
		contact++;
	if (check_contact(tetri, x, y + 1))
		contact++;
	if (check_contact(tetri, x, y - 1))
		contact++;
	return (contact);
}

/*
 ** Check if model is valid.
 ** Return 1 if is valid, else 0.
*/

static int	check_model(t_tetri *model)
{
	int		x;
	int		y;
	int		contact;
	int		nb_blocks;

	if (!model)
		return (0);
	x = -1;
	contact = 0;
	nb_blocks = 0;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (model->tetri[x][y] != '.')
			{
				contact += block_contact(model->tetri, x, y);
				nb_blocks++;
				if (nb_blocks > 4)
					return (0);
			}
		}
	}
	return (nb_blocks == 4 && (contact == 3 || contact == 6 || contact == 8));
}

/*
 ** Check if all model are valid. models must be NULL finished.
 ** Return 1 if all are valid, else 0.
*/

int		model_is_valid(t_tetri **models)
{
	int		i;

	if (!(*models))
		return (0);
	i = 0;
	while (models[i])
	{
		if (!check_model(models[i]))
			return (0);
		i++;
	}
	return (1);
}
