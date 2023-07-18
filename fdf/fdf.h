/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:21 by subpark           #+#    #+#             */
/*   Updated: 2023/07/18 16:50:23 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "libft.a"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

 typedef struct	matrixes
 {
	float	rotate[3][3];
	float	projectxy[3][3];
	float	a;
	float	b;
	float	c;
/*
	a = 1;
	b = 1;
	c = 1;
	rotate = {
				{cos(a) * cos(b), cos(a) * sin(b) * sin(c) - sin(a) * cos(c), cos(a) * sin(b) * cos(c) + sin(a) * sin(c)},
				{sin(a) * cos(b), sin(a) * sin(b) * sin(c) + cos(a) * cos(c), sin(a) * sin(b) * cos(c) - cos(a) * sin(c)},
				{-sin(b), cos(b) * sin(c), cos(b) * cos(c)}
			};
	projectxy = {{1, 0, 0}, {0, 1, 0}, {0, 0, 0}};*/
 }					t_matrix ;

int		count_lines(int fd);
char	**load_map1(const char *path);
char	***load_map2(char **map1);
float	**alloc_array(char ***map);
float	**put_data(float **array, char	***map);


#endif