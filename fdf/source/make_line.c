/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:50:52 by siun              #+#    #+#             */
/*   Updated: 2023/08/03 16:36:11 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + y * data->line_length + x * (data->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}

int	newcolor(int pix)
{
	return (0xff000000 + 0x00000100 * (255 - pix) + pix);
}

int		max_z(float	**map)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	max = 0;
	min = 0;
	while (map[i] != NULL)
	{
		if (max < map[i][2])
			max = map[i][2];
		if (min > map[i][2])
			min = map[i][2];
		i ++;
	}
	return (max - min);
}

void	make_line(t_data image, float **map, float *dot1, float *dot2, int max_z)
{
	int		pixels;
	int		color;
	float	deltax;
	float	deltay;
	float	deltaz;

	if (dot1 == NULL || dot2 == NULL)
		return ;
	pixels = sqrt((dot1[0] - dot2[0]) * (dot1[0] - dot2[0])
					+ (dot1[1] - dot2[1]) * (dot1[1] - dot2[1]));
	deltax = (dot2[0] - dot1[0]) / pixels;
	deltay = (dot2[1] - dot1[1]) / pixels;
	deltaz = (dot2[2] - dot1[2]) / pixels;
	while (pixels)
	{
		if (dot1[0] + deltax * pixels <= IMG_WIDTH &&
			dot1[1] + deltay * pixels <= IMG_HEIGHT)
			my_mlx_pixel_put(&image, dot1[0] + deltax * pixels,
		 	dot1[1] + deltay * pixels, newcolor((dot1[2] + deltaz * pixels)
					* 255 / max_z));
		pixels --;
	}
}

void	print_out(float **map, t_data image, const char *path, int max_z)
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
		if (i + movement_y < data_length)
			make_line (image, map, map[i], map[i + movement_y], max_z);
		if (i + 1 < data_length && (i + 1) % movement_y != 0)
			make_line (image, map, map[i], map[i + 1], max_z);
		free(map[i]);
		i ++;
	}
	free(map);
}