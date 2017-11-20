/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:32:08 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/20 16:11:56 by bpisano          ###   ########.fr       */
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

void		print_table(char **table)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%c", table[i][j]);
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

char		**char_model(char **str, int index)
{
	int 	i;
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

t_tetri		**model(char **str, int t_n)
{
	int		i;
	//t_tetri	*tetri;
	t_tetri	**model;

	if (!(model = (t_tetri **)malloc(sizeof(t_tetri *) * (t_n + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!(model[i] = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		model[i]->tetri = char_model(&str[i], i / 4);
		model[i]->width = 0;
		model[i]->height = 0;
		//model[i / 4] = tetri;
		i += 4;
	}
	model[i / 4] = NULL;
	print_model(model);
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
