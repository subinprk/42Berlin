/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:20:21 by subpark           #+#    #+#             */
/*   Updated: 2023/08/03 16:31:43 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#  define IMG_WIDTH 1000
#  define IMG_HEIGHT 1000
# endif

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_print
{
	int	x;
	int	y;
	int	size;
}				t_print;


char	*get_next_line(int fd);
int		merging(char *buff, char **str, int start, int index);
int		count_lines(int fd);
char	**load_map1(const char *path);
int		count_rows(void **map);
char	***load_map2(char **map1);
float	**alloc_array(char ***map);
float	**put_data(float **array, char	***map);
void	make_angle(float a, float b, float c, float (*angle)[3][3]);
void	rotate(float ***array);
void	pro_vect(float	(*project)[3][3]);
void	project(float   ***array);
void	make_line(t_data image, float **map, float *dot1, float *dot2, int max_z);
void	print_out(float **map, t_data image, const char *path, int max_z);
float	**total_map(char *path);
void	make_distanced(float ***array, int x, int y, int size);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		max_z(float	**map);

#endif