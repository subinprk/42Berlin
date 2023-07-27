/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_cal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:56:20 by subpark           #+#    #+#             */
/*   Updated: 2023/07/27 18:05:19 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	**angle(float a, float b, float c)
{
	float	angle[3][3];

	angle = {
				{cos(a) * cos(b), cos(a) * sin(b) * sin(c) - sin(a) * cos(c), cos(a) * sin(b) * cos(c) + sin(a) * sin(c)},
				{sin(a) * cos(b), sin(a) * sin(b) * sin(c) + cos(a) * cos(c), sin(a) * sin(b) * cos(c) - cos(a) * sin(c)},
				{-sin(b), cos(b) * sin(c), cos(b) * cos(c)}
			};
	return ((float **)angle);
}

void	rotate(float **angle, float ***array)
{
	float   tmp[3];
	int		i;
	int		j;

	i = 0;
	while (*array[i] != NULL)
	{
		j = 0;
		while (j < 3)
		{
			tmp[j] = (*array[i][0]) * angle[0][j]
					+ (*array[i][1]) * angle[1][j]
					+ (*array[i][2]) * angle[2][j];
			j ++;
		}
		*array[i][0] = tmp[0];
		*array[i][1] = tmp[1];
		*array[i][2] = tmp[2];
		i ++;
	}
}

void	pro_vect(float	***project)
{
	*project[0][0] = 1;
	*project[0][1] = 0;
	*project[0][2] = 0;
	*project[1][0] = 0;
	*project[1][1] = 1;
	*project[1][2] = 0;
	*project[2][0] = 0;
	*project[2][1] = 0;
	*project[2][2] = 0;
}

float	**project(float   **array)
{
	float   project[3][3];
	float	tmp[3];
	float	**newarr;
	int		i;
	int		j;

	pro_vect((float ***)&project);
	newarr = ft_calloc(sizeof(float *), count_rows((void **)array) + 1);
	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		newarr[i] = ft_calloc(sizeof(float), 2);
		while (j < 2)
		{
			tmp[j] = (array[i][0]) * project[0][j]
					+ (array[i][1]) * project[1][j]
					+ (array[i][2]) * project[2][j];
			newarr[i][j] = tmp[j];
			j ++;
		}
		free(array[i]);
		i ++;
	}
	newarr[i] = NULL;
	free(array);
	return (newarr);
}