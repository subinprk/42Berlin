/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:21 by subpark           #+#    #+#             */
/*   Updated: 2023/07/27 17:35:50 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
int		merging(char *buff, char **str, int start, int index);
int		count_lines(int fd);
char	**load_map1(const char *path);
int		count_rows(void **map);
char	***load_map2(char **map1);
float	**alloc_array(char ***map);
float	**put_data(float **array, char	***map);
float	**angle(float a, float b, float c);
void	rotate(float **angle, float ***array);
float	**project(float   **array);

#endif