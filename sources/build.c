/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:32:08 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/20 14:18:35 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>
int			split_len(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void		print_table(int **table)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d", table[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		print_model(t_tetri **mod)
{
	int		i;

	i = 0;
	while (mod[i])
	{
		print_table(mod[i]->tetri);
		i++;
	}
}

int			**int_model(char **str)
{
	int 	i;
	int		j;
	int		**tetri;

	if (!(tetri = (int **)malloc(sizeof(int *) * 5)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		if (!(tetri[i] = (int *)malloc(sizeof(int) * 4)))
			return (NULL);
		while (j < 4)
		{	
			tetri[i][j] = str[i][j] == '.' ? 0 : 1;
			j++;
		}
		i++;
	}
	tetri[i] = NULL;
	return (tetri);
}

t_tetri		*new_tetri(int **tetri_table)
{
	t_tetri	*new;

	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	new->tetri = tetri_table;
	new->width = 0;
	new->height = 0;
	return (new);
}

t_tetri		**model(char **str, int t_n)
{
	int		i;
	t_tetri	**model;

	if (!(model = (t_tetri **)malloc(sizeof(t_tetri *) * (t_n + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!(model[i / 4] = new_tetri(int_model(&str[i]))))
			return (NULL);
		i += 4;
	}
	model[i / 4] = NULL;
	return (model);
}

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
