/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:33:56 by bpisano           #+#    #+#             */
/*   Updated: 2017/11/16 18:40:57 by bpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

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

static int	lines_per_tetri_is_valid(char *str)
{
	int		i;
	int		lines;

	i = 0;
	while (str[i])
	{
		lines = 0;
		while (line_len(&str[i]) == 4 && lines < 4 && str[i])
		{
			lines++;
			i += line_len(&str[i]) + 1;
		}
		if (str[i] == '\n' && line_len(&str[i]) == 0)
			i++;
		if ((str[i] != '\n' && str[i] != '\0') || lines != 4)
			return (0);	
		return (lines_per_tetri_is_valid(&str[i]));
	}
	return (1);
}

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
   static int	character_are_valid(char *str)
   {
   int		i;

   i = 0;
   while (str[i])
   {
   if (!(str[i] == '.' || str[i] == '#' || str[i] == '\n'))
   return (0);
   i++;
   }
   return (1);
   }*/

int		content_file_is_valid(char *content)
{
	return (char_per_line_is_valid(content));
}

int		main()
{
	printf("%d", lines_per_tetri_is_valid("....\n....\n....\n....\n\n....\n....\n....\n...."));
	return (0);
}
