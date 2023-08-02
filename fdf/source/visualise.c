/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:18:50 by siun              #+#    #+#             */
/*   Updated: 2023/08/02 17:59:49 by subpark          ###   ########.fr       */
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
	rotate(&array);
	project(&array);
	//make_distanced(&array);
	return (array);
}

void	increase_x(int key, int *x)
{
	if (key == XK_Right)
		*x = *x + 1;
	else if (key == XK_Left)
		*x = *x - 1;
}

void	increase_y(int key, int *y)
{
	if (key == XK_Up)
		*y = *y + 1;
	else if (key == XK_Down)
		*y = *y - 1;
}

int	destroy_win(int key, t_vars *vars, t_data image)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	manage_hook(int key, t_vars *vars, t_data image)
{}

int	main(int argc, char **argv)
{
	float	**map;
	static int		x;
	static int		y;
	static int		size;
	t_data	image;
	t_vars	vars;

	map = total_map(argv[1]);
	make_distanced(&map, x, y, size);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, IMG_WIDTH, IMG_HEIGHT, "Hello world!");
	image.img = mlx_new_image(vars.mlx, IMG_WIDTH, IMG_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, 
								&image.line_length, &image.endian);
	print_out(map, image, argv[1]);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, destroy_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}