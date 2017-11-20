/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:28:20 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/20 13:44:39 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

# define BUF_SIZE 128

typedef struct	s_tetri
{
	int			**tetri;
	int			width;
	int			height;
}				t_tetri;

char			*read_file(char *file_name);
int				input_is_valid(char *str);
t_tetri			**build_model(char *str);
int				model_is_valid(t_tetri **models);
#endif
