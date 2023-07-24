/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:54:12 by subpark           #+#    #+#             */
/*   Updated: 2023/07/24 18:49:07 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	**alloc_array(char ***map)
{
	float	**container;
	int		nodes;
	int		i;
	int		j;

	container = NULL;
	//nodes = sizeof(map) / sizeof(char *);
	i = 0;
	nodes = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[j] != NULL)
		{
			nodes ++;
			free(map[i][j]);
			j ++;
		}
		free(map[i]);
		i ++;
	}
	free(map);
	*container = ft_calloc (sizeof(float *), nodes + 1);
	i = 0;
	while (i < nodes)
	{
		container = ft_calloc(sizeof(float), 3);
		i ++;
	}
	return (container);
}

float	**put_data(float **array, char	***map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != NULL)
		{
			array[count][0] = i;
			array[count][1] = j;
			array[count][2] = ft_atoi(map[i][j]);
			free(map[i][j]);
			j ++;
			count ++;
		}
		free(map[i]);//freeing, dimension of map could be problem.
		i ++;
	}
	free(map);
	return (array);
}

int main()
{
	int	i;
	int	j;
	int	fd;
	float	**array;
	char	***tmp;
	char	**arr;

//for check countline
/*	fd = open("42.fdf", O_RDONLY);
	i = count_lines(fd);
	printf("%d", i);
*/

//for checking load map1
/*
	arr = load_map1("42.fdf");
	i = 0;
	while(i < count_rows(arr))
	{
		printf("%s", arr[i]);
		i ++;
	}
*/

//for checking load map 2
/*	tmp = load_map2(load_map1("42.fdf"));
	i = 0;
	while (tmp[i] != NULL)
	{
		j = 0;
		while (tmp[i][j] != NULL)
		{
			printf("%s ", tmp[i][j]);
			free(tmp[i][j]);
			j ++;
		}
		free(tmp[i]);
		printf("\n");
		i ++;
	}
	free(tmp);
*/

	tmp = load_map2(load_map1("42.fdf"));
	array = put_data(alloc_array(tmp), tmp);
	i = 0;
	j = 0;
	while (tmp[i] != NULL)
	{
		j = 0;
		while (tmp[i][j] != NULL)
		{
			printf("%f, ", array[i][j]);
			j ++;
		}
		free(array[i]);
		printf("\n");
		i ++;
	}
	free(array);

	return (0);
}