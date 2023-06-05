/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:28:33 by subpark           #+#    #+#             */
/*   Updated: 2023/06/05 17:37:30 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	int		count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	count = put_in_buffer(int fd);
	if (str)
		free(str);
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	read(fd, str, count - 1);
	str[count - 1] = '\n';
	str[count] = '\0';
	return (str);
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