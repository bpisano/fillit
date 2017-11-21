/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:32:08 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/21 17:49:27 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 ** Create a char table with the correct letter of the str passed in parameters.
 ** Return the char table.
*/

static char			**char_model(char **str, int index)
{
	int		i;
	int		j;
	char	**tetri;

	if (!(tetri = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		if (!(tetri[i] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		while (j < 4)
		{
			tetri[i][j] = str[i][j] == '.' ? '.' : 'A' + index;
			j++;
		}
		tetri[i][j] = '\0';
		i++;
	}
	tetri[i] = NULL;
	return (tetri);
}

/*
 ** Create the structure model of a tetrimino.
 ** Return a list of type t_tetri.
*/

static t_list		*model(char **str)
{
	int		i;
	t_tetri	*tetri;
	t_list	*model;

	model = NULL;
	i = 0;
	while (str[i])
	{
		if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		tetri->tetri = char_model(&str[i], i / 4);
		tetri->width = 0;
		tetri->height = 0;
		ft_lst_push_back(&model, ft_lstnew(tetri, sizeof(tetri)));
		i += 4;
	}
	return (model);
}

/*
 ** Create a list of t_tetri with the input in parameters.
 ** Return the list of tetriminos.
*/

t_list				*build_model(char *str)
{
	char	**split;

	split = ft_strsplit(str, '\n');
	return (model(split));
}
