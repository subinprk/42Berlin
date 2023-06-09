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
int	copybuff(char *buff, char **str, int index)
{
	*str = malloc(index + 2);
	if (!str)
		return (0);
	ft_strlcat(*str, buff, index);
	*str[index] = '\n';
	*str[index + 1] = '\0';
}

int	merging(char *buff, char **str, int index)
{
	char	*tmp;

	tmp = NULL;
	if (*str == NULL)
	{
		copybuff(buff, str, index);
		if (!(*str))
			return (0);
	}
	else
		tmp = ft_strdup(*str);
		if(!tmp)
			return (0);
		free (*str);
		*str = malloc(ft_strlen(tmp) + )
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*str;
	int		tmp;
	int		index;

	str = NULL;
	buff = (char *)malloc(BUFFER_SIZE);
	tmp = read(fd, buff, BUFFER_SIZE - 1);
	buff[BUFFER_SIZE -1] = '\0';
	while (tmp > 0)
	{
		index = 0;
		while (buff[index] != '\0' && buff[index] != '\n')
			index ++;
		merging(buff, &str, index);
		if (index != BUFFER_SIZE - 1)
			return (str);
		tmp = read(fd, buff, BUFFER_SIZE - 1);
		if (tmp < 0)
			return (str);
		buff[BUFFER_SIZE -1] = '\0';
	}
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