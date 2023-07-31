/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:18:50 by siun              #+#    #+#             */
/*   Updated: 2023/07/31 16:56:44 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	**total_map(char *path)
{
	char	***tmp;
	char	**arr;
	float	**array;

	tmp = load_map2(load_map1(path));
	array = put_data(alloc_array(tmp), tmp);
	return (array);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	float	**map;
	t_data	image;

	map = total_map(argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	image.img = mlx_new_image(mlx, 500, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, 
								&image.line_length, &image.endian);
	print_out(map, image, argv[1]);
	//my_mlx_pixel_put(&image, 10, 10, 0x0000ff00);
	mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}