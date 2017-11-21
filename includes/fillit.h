/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:28:20 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/21 16:50:21 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

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
}				t_map;

char			*read_file(char *file_name);
int				input_is_valid(char *str);
t_list			**build_model(char *str);
int				model_is_valid(t_list **models);
void			adjust(t_list **model);
#endif
