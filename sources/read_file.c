/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:12:59 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 12:13:09 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 ** read all bytes in the file "file_name" and stock them in an allocated string
 ** return NULL if any problem, else return the string.
*/

char	*read_file(char *file_name)
{
	int		fd;
	char	*text;
	char	buffer[BUF_SIZE + 1];
	int		ret;
	char	*last_text;

	text = ft_strdup("");
	if (!text || !file_name)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, buffer, BUF_SIZE)))
	{
		buffer[ret] = '\0';
		last_text = text;
		text = ft_strjoin(text, buffer);
		free(last_text);
		last_text = NULL;
		if (!text)
			return (NULL);
	}
	close(fd);
	return (text);
}
