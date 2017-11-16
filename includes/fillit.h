/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:28:20 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/16 17:35:10 by htaillef         ###   ########.fr       */
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
int				content_file_is_valid(char *str);
t_tetri			**build_model(char *str);
int				model_is_valid(t_tetri **models, int nb_models);
#endif
