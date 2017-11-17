/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.C                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:32:08 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/17 15:56:01 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			split_len(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

t_tetri		*build_model(char *str)
{
	char	**split;
	int		t_n;
	t_tetri	**tetri_list;

	split = ft_strsplit(str, '\n');
	t_n = split_len(split);
	if (!(tetri_list = (t_tetri **)malloc(sizeof(t_tetri *) * (t_n + 1))))
		return (NULL);
	
	return (NULL);
}
