/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:54:12 by subpark           #+#    #+#             */
/*   Updated: 2023/07/18 15:37:49 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	**alloc_array(char ***map)
{
	float	**container;
	int		nodes;
	int		i;

	container = NULL;
	nodes = sizeof(map) / sizeof(char *);
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
	while (i < (int)(sizeof(map) / sizeof(*map)))
	{
		j = 0;
		while (j < (int)(sizeof(map) / sizeof(*map[i])))
		{
			array[count][0] = i;
			array[count][1] = j;
			array[count][2] = ft_atoi(map[i][j]);
			free(map[i][j]);
			count ++;
		}
		free(map[i]);//freeing, dimension of map could be problem.
	}
	free(map);
	return (array);
}

int main()
{
	int	i;
	int	j;
	float	**array;
	char	***tmp;

	tmp = load_map2(load_map1("42.fdf"));
	array = put_data(alloc_array(tmp), tmp);
	i = 0;
	j = 0;
	while (i < (int)(sizeof(array) / sizeof(array[i])))
	{
		j = 0;
		while (j < 3)
		{
			printf("%f, ", array[i][j]);
			j ++;
		}
		printf("\n");
		i ++;
	}
	return (0);
}