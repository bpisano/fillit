/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:10:16 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 13:40:26 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*input_process(char *file_name)
{
	char	*input;

	if (!(input = read_file(file_name)))
		return (NULL);
	if (!input_is_valid(input))
		return (NULL);
	return (input);
}

t_list	*model_process(char *input)
{
	t_list	*model;

	model = build_model(input);
	if (!model || ft_lstlen(model) == 0 || ft_lstlen(model) > 26
			|| !model_is_valid(&model))
		return (NULL);
	return (model);
}

t_map	*map_process(t_list *model)
{
	t_map	*map;

	if (!(map = build_map(&model)))
		return (NULL);
	return (map);
}

void	fillit(char *file_name)
{
	char	*input;
	t_list	*model;
	t_map	*map;

	if (!(input = input_process(file_name)))
	{
		ft_putstr("error\n");
		return ;
	}
	if (!(model = model_process(input)))
	{
		ft_putstr("error\n");
		return ;
	}
	free(input);
	input = NULL;
	adjust(&model);
	if (!(map = map_process(model)))
	{
		ft_putstr("error\n");
		return ;
	}
	solve(map);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		usage();
		return (0);
	}
	fillit(av[1]);
	return (0);
}
