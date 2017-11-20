/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:32:08 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/20 13:49:41 by bpisano          ###   ########.fr       */
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

	(void)str;
	if (!(tetri = (int **)malloc(sizeof(int *) * 5)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!(tetri[i] = (int *)malloc(sizeof(int) * 4)))
				return (NULL);
			tetri[i][j] = 2/*str[i][j] == '.' ? 1 : 0*/;
			//printf("%c", str[i][j]);
			j++;
		}
		//printf("\n");
		i++;
	}
	//tetri[i] = NULL;
	print_table(tetri);
	return (tetri);
}

t_tetri		**model(char **str)
{
	int		i;
	t_tetri	**model;
	t_tetri	*tetri;

	if (!(model = (t_tetri **)malloc(sizeof(t_tetri *) + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		tetri->tetri = int_model(&str[i]);
		//print_table(tetri->tetri);
		tetri->width = 0;
		tetri->height = 0;
		model[(i / 4) - 1] = tetri;
		i += 4;
		printf("\n");
	}
	model[(i / 4) - 1] = NULL;
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
	t_model = model(split);
	//print_model(t_model);
	return (t_model);
}
