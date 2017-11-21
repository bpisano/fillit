/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:14:27 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/21 17:47:14 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	char	*input;
	t_list	*model;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	input = read_file(av[1]);
	if (!input_is_valid(input))
	{
		ft_putstr("error\n");
		return (0);
	}
	model = build_model(input);
	if (!model_is_valid(&model))
	{
		ft_putstr("error\n");
		return (0);
	}
	adjust(&model);
	map = build_map(&model);
	printf("%d", map->size);
	return (0);
}
