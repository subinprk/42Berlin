/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:20:31 by subpark           #+#    #+#             */
/*   Updated: 2023/06/05 17:37:31 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char    *put_in_buffer(int fd)
{
	char	*buffer;
	int		count;

	count = 0;
	buffer = malloc (BUFFER_SIZE * sizeof (char));
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE - 1);
	buffer[BUFFER_SIZE - 1] = '\0';
	return (buffer);
}

char    *make_line(int fd)
{
	char	*buffer;
	static int	index;
	int		count;
	int		prvsize;
	char	*prvbuff[2];

	buffer = put_in_buffer(fd);
	if (!buffer)
		return (NULL);
	count = 0;
	prvsize = 0;
	while (buffer > 0)
	{
		index = 0;
		while (buffer[index] != '\0' && buffer[index] != '\n')
		{
			index ++;
			count ++;
		}
		if (buffer[index] =='\0')
		{
			prvsize ++;
			if(prvbuff[1])
			{
				prvbuff[0] = malloc(sizeof(prvbuff[1]) * sizeof(char));
				prvbuff[0] = prvbuff[1];
				free(prvbuff[1]);
			}
			prvbuff[1] = (char *)malloc(sizeof(char) * sizeof(buffer));
			prvbuff[1] = buffer;
			buffer = put_in_buffer(fd);
		}
	}
	


}