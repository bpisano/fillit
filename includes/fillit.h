/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:28:20 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/22 19:14:57 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

# include <stdio.h>

# define BUF_SIZE 256

typedef struct	s_tetri
{
	char		**tetri;
	int			width;
	int			height;
	int			x;
	int			y;
}				t_tetri;
typedef struct	s_map
{
	char		**map;
	int			size;
	t_list		*todo;
	t_list		*placed;
}				t_map;

char			*read_file(char *file_name);
int				input_is_valid(char *str);
t_list			*build_model(char *str);
int				model_is_valid(t_list **models);
void			adjust(t_list **model);
t_map			*build_map(t_list **model);
void			set_min_pos(char **tetri, int *min_x, int *min_y);
void			set_max_pos(char **tetri, int *max_x, int *max_y);
void			solve(t_map *map);
void			print_map(char **map);
#endif
