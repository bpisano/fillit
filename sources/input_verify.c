/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:33:56 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/20 16:30:03 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 ** Calculate the len of a line ended by a \n.
 ** Return the len of the line.
*/

static int	line_len(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != '\n' && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

/*
 ** Check if all char are valid and if char count is gratter or equal than 12.
 ** Return 1 if all are valid, else 0.
*/

static int	valid_char(char *str)
{
	int		i;
	int		d;
	int		p;
	int		b;

	i = 0;
	d = 0;
	p = 0;
	b = 0;
	while (str[i])
	{
		if (!(str[i] == '#' || str[i] == '.' || str[i] == '\n'))
			return (0);
		str[i] == '#' ? d++ : d;
		str[i] == '.' ? p++ : p;
		str[i] == '\n' ? b++ : b;
		i++;
	}
	return (b >= 4 && d + p >= 8);
}

/*
 ** Check if there is not more 5 char per lines or if line is only \n.
 ** Return 1 if all are valid, else 0.
*/

static int	char_per_line_is_valid(char *str)
{
	int		i;
	int		len;

	i = 0;
	while (str[i])
	{
		len = line_len(&str[i]);
		i += len;
		if (len == 0)
			i++;
		if (!(len == 0 || len == 4))
			return (0);
	}
	return (1);
}

/*
 ** Check if there is 4 line followed by a \n.
 ** Return 1 if all are valid, else 0.
*/

static int	lines_per_tetri_is_valid(char *str)
{
	int		i;
	int		line_index;
	int		offset;

	if (str[0] == '\n' || (str[ft_strlen(str) - 1] != '\n' &&
				str[ft_strlen(str) - 2] != '\n'))
		return (0);
	i = 5;
	line_index = 1;
	while (str[i])
	{
		offset = (line_index / 4) - 1 < 0 ? 0 : (line_index / 4) - 1;
		if (!(line_len(&str[i]) == 0 && (line_index - offset) % 4 == 0) &&
				!(line_len(&str[i]) == 4 && (line_index - offset) % 4 != 0))
		{
			return (0);
		}
		line_index++;
		i += line_len(&str[i]) + 1;
	}
	return ((line_index - offset) % 4 == 0);
}

/*
 ** Check if the input is valid.
 ** Return 1 if all is valid, else 0.
*/

int			input_is_valid(char *content)
{
	return (valid_char(content) &&
			char_per_line_is_valid(content) &&
			lines_per_tetri_is_valid(content));
}
