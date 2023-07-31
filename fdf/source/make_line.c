/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:50:52 by siun              #+#    #+#             */
/*   Updated: 2023/07/31 17:02:50 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + y * data->line_length + x * (data->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}

void	make_line(t_data image, float *dot1, float *dot2)
{
	int		pixels;
	float	deltax;
	float	deltay;

	if (dot1 == NULL || dot2 == NULL)
		return ;
	pixels = sqrt((dot1[0] - dot2[0]) * (dot1[0] - dot2[0])
					+ (dot1[1] - dot2[1]) * (dot1[1] - dot2[1]));
	deltax = (dot2[0] - dot1[0]) / pixels;
	deltay = (dot2[1] - dot1[1]) / pixels;
	while (pixels)
	{
		my_mlx_pixel_put(&image, dot1[0], dot1[1], 0x00ffffff);
		dot1[0] = dot1[0] + deltax;
		dot1[1] = dot1[1] + deltay;
		pixels --;
	}
}

void	print_out(float **map, t_data image, const char *path)
{
	int		data_length;
	int		standard_y;
	int		movement_y;
	int		i;
	int		j;

	i = open(path, O_RDONLY);
	standard_y = count_lines(i);
	close(i);
	data_length = count_rows((void **)map);
	movement_y = data_length / standard_y;
	i = 0;
	while (i < data_length)
	{
		if (i + 1 < data_length)
			make_line (image, map[i], map[i + 1]);
		if (i + movement_y < data_length)
			make_line (image, map[i], map[i + movement_y]);
		free(map[i]);
		i ++;
	}
	free(map);
}