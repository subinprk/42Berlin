/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:28:33 by subpark           #+#    #+#             */
/*   Updated: 2023/06/13 12:52:52 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct s_buf
{
	char	buff[BUFFER_SIZE];
	int		index;
	int		tmp;
};

int	merging(char *buff, char **str, int start, int index)
{
	char	*tmp;

	tmp = NULL;
	if (*str)
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = malloc(ft_strlen(tmp) + index - start + 1);
		(*str)[0] = '\0';
		ft_strlcat(*str, tmp, ft_strlen(tmp) + 1);
		ft_strlcat(*str, buff + start, ft_strlen(tmp) + index - start + 1);
		free(tmp);
	}
	else
	{
		*str = malloc(index - start + 1);
		if (!(*str))
			return (0);
		(*str)[0] = '\0';
		ft_strlcat(*str, buff + start, index - start + 1);
	}
	return (0);
}

int	add_newline(char **str)
{
	char	*tmp;

	tmp = ft_strdup((*str));
	if (!tmp)
		return (0);
	free (*str);
	*str = malloc(ft_strlen(tmp) + 2);
	(*str)[0] = '\0';
	ft_strlcat(*str, tmp, ft_strlen(tmp) + 1);
	(*str)[ft_strlen(tmp)] = '\n';
	(*str)[ft_strlen(tmp) + 1] = '\0';
	free(tmp);
	return (1);
}

char	*get_next_line(int fd)
{
	static struct s_buf	buf;
	char	*str;
	int		start;

	str = NULL;
	if (buf.buff[0] == '\0')
		buf.tmp = read(fd, buf.buff, BUFFER_SIZE);
	while (buf.tmp > 0)
	{
		start = buf.index;
		while (buf.index < buf.tmp && buf.buff[buf.index] != '\n' && buf.buff[buf.index] != '\0')
			buf.index ++;
		merging(buf.buff, &str, start, buf.index);
		if (buf.index < buf.tmp)
		{
			buf.index ++;
			break;
		}
		else if (buf.index == buf.tmp)
		{
			ft_bzero(buf.buff, buf.tmp);
			buf.tmp = read(fd, buf.buff, BUFFER_SIZE);
			buf.index = 0;
		}
		else
			buf.index ++;
	}
	if(!add_newline(&str))
		return (NULL);
	return (str);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
	const char	*filename = "tmp";
	char	*str;
	int fd = open(filename, O_RDONLY);
	if (fd < 3)
		return 0;
	
	str = get_next_line(fd);
	printf("first line : %s", str);
	free(str);
	str = get_next_line(fd);
	printf("second line : %s", str);
	free(str);
	return 0;
}*/