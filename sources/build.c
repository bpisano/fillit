/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:32:08 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/20 16:38:02 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 ** Calculate the len of the input splited.
 ** Return the len of the split.
*/

int			split_len(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

/*
 ** Create a char table with the correct letter of the str passed in parameters.
 ** Return the char table.
*/

char		**char_model(char **str, int index)
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

t_tetri		**model(char **str, int t_n)
{
	int		i;
	t_tetri	*tetri;
	t_tetri	**model;

	if (!(model = (t_tetri **)malloc(sizeof(t_tetri *) * (t_n + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		tetri->tetri = char_model(&str[i], i / 4);
		tetri->width = 0;
		tetri->height = 0;
		model[i / 4] = tetri;
		i += 4;
	}
	model[i / 4] = NULL;
	return (model);
}

/*
 ** Create a list of t_tetri with the input in parameters.
 ** Return the list of tetriminos.
*/

t_tetri		**build_model(char *str)
{
	char	**split;
	int		t_n;
	t_tetri	**t_model;

	split = ft_strsplit(str, '\n');
	t_n = split_len(split) / 4;
	if (!(t_model = (t_tetri **)malloc(sizeof(t_tetri *) * (t_n + 1))))
		return (NULL);
	t_model = model(split, t_n);
	return (t_model);
}
