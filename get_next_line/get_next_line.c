/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:28:33 by subpark           #+#    #+#             */
/*   Updated: 2023/06/09 15:47:43 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct buf
	{
		char	buff[BUFFER_SIZE];
		int		index;
	};

int	merging(char *buff, char **str, int start, int index)
{
	char	*tmp;

	if (*str)
	{
		tmp = ft_strdup(*str, start);
		free(*str);
		*str = malloc(ft_strlen(tmp) + index - start + 1);
		ft_strlcat(*str, tmp + start, ft_strlen(tmp) + 1);
		ft_strlcat(*str, buff + start, ft_strlen(tmp) + index - start + 1);
		free(tmp);
	}
	else
		*str = ft_strdup(buff, start);
	return (0);
}

char	*add_newline(char **str)
{
	char	*tmp;

	tmp = malloc(ft_strlen(*str) + 2);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	ft_strlcat(tmp, *str, ft_strlen(*str) + 1);
	tmp[ft_strlen(*str)] = '\n';
	tmp[ft_strlen(*str) + 1] = '\0';
	free (*str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static struct buf buf;
	char	*str;
	int		start;
	int		tmp;

	tmp = 0;
	start = 0;
	if (buf.buff[0] == '\0')
	{
		tmp = read(fd, buf.buff, BUFFER_SIZE - 1);
		buf.buff[BUFFER_SIZE - 1] = 0;
	}
	else
		start = buf.index;
	while (tmp > 0)
	{
		while (buf.buff[buf.index] != '\0' && buf.buff[buf.index] != '\n')
			buf.index ++;
		if (buf.index != BUFFER_SIZE - 1)
		{
			merging(buf.buff, &str, start, buf.index);
			break;
		}
		tmp = read(fd, buf.buff, BUFFER_SIZE - 1);
		merging(buf.buff, &str, start, buf.index);
		start = 0;
	}
	return (add_newline(&str));
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
	free(str);
	str = get_next_line(fd);
	printf("Contents of the Second line : %s", str);
	free(str);
	str = get_next_line(fd);
	printf("Contents of the Third line : %s", str);
	free(str);
	return 0;
}