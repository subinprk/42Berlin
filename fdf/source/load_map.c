/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:08 by subpark           #+#    #+#             */
/*   Updated: 2023/07/24 18:15:04 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//I have to think about the free dynamically allocated arrays.........

#include "fdf.h"

int	count_lines(int fd)
{
	int		lines;
	char	*tmp;

	lines = 0;
	tmp = get_next_line(fd);
	while (tmp > 0)
	{
		free(tmp);
		lines ++;
		tmp = get_next_line(fd);
	}
	return (lines);
}

char	**load_map1(const char *path)
{
	char	**map1;
	int		lines;
	int 	fd;
	int		i;

	map1 = NULL;
	fd = open(path, O_RDONLY);
	lines = count_lines(fd);
	close(fd);
	map1 = (char **)ft_calloc(sizeof(char *), lines + 1);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < lines)
	{
		map1[i] = get_next_line(fd);
		i ++;
	}
	close(fd);
	return (map1);
}

int		count_rows(char **map)
{
	int	row;

	row = 0;
	while (map[row] != NULL)
		row ++;
	return (row);
}

char	***load_map2(char **map1)
{
	char	***map2;
	int		row;
	int		i;

	map2 = NULL;
	row = count_rows(map1);
	map2 = (char ***)malloc(sizeof(char **)*(row + 1));
	//Possible error point. i Don't know about eof, null pointer in the last line
	i = 0;
	while (i < row)
	{
		map2[i] = ft_split(map1[i], ' ');
		free(map1[i]);
		//also not sure bout this point, bcuzof the deapth of pointer map1
		i ++;
	}
	map2[row] = NULL;
	free(map1);
	return (map2);
}