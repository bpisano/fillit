/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:14:27 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/20 12:59:42 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	char	*input;
	int		size;
	t_tetri	**model;

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
	model = build_model(input, &size);	
	if (!model_is_valid(model, size))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}
