/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:18:50 by siun              #+#    #+#             */
/*   Updated: 2023/08/07 20:07:32 by siun             ###   ########.fr       */
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

int	destroy_win(int key, t_vars *vars)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	exit_button(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	float	**map;
	t_data	image;
	t_vars	vars;
	t_print	print;
	int		height;

	if (argc != 2)
		return (0);
	map = total_map(argv[1]);
	if (!map)
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, IMG_WIDTH, IMG_HEIGHT, "fdf");
	image.img = mlx_new_image(vars.mlx, IMG_WIDTH, IMG_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, 
			&image.line_length, &image.endian);
	make_distanced(&map, print.x, print.y);
	height = max_z(map);
	print_out(map, image, argv[1], height);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, &destroy_win, &vars);
	mlx_hook(vars.win, 17, 0, &exit_button, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
