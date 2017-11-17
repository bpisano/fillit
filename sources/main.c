/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:14:27 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/17 12:44:36 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	char	*input;

	if (ac != 2)
	{
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	input = read_file(av[1]);
	if (!input_is_valid(input))
	{
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	ft_putstr(read_file(av[1]));
	return (0);
}
