/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:28:33 by subpark           #+#    #+#             */
/*   Updated: 2023/06/06 17:02:45 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *make_line(int fd)
{
	static int	index;
	int		prvsize;
	char	*buff[3];

	buff[0] = malloc (BUFFER_SIZE * sizeof (char));
		if (!buff[0])
			return (NULL);
	buff[0] = put_in_buffer(fd, buff[0]);
	buff[1] = NULL;
	buff[2] = NULL;
	if (!buff[0])
		return (NULL);
	prvsize = 0;
	while (buff[0] != NULL)
	{
		index = 0;
		while (buff[0][index] != '\0' && buff[0][index] != '\n')
			index ++;
		if(!savewithprv(&buff, index, fd))
			return (NULL);
		if (buff[0][index] == '\0' || buff[0][index] == '\n')
		{
			free(buff[0]);
			return (buff[1]);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int		count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	return (make_line(fd));
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	const char	*filename = "tmp";
	char	*str;
	int fd = open(filename, O_RDONLY);
	if (fd < 3)
		return 0;
//	printf("length of line %d\n", length_of_line(fd));
	str = get_next_line(fd);
	printf("Contents of the First line : %s", str);
	str = get_next_line(fd);
	printf("Contents of the Second line : %s", str);
	str = get_next_line(fd);
	printf("Contents of the Third line : %s", str);
	free(str);
	return 0;
}