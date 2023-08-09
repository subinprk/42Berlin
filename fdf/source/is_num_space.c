/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:57:32 by subpark           #+#    #+#             */
/*   Updated: 2023/08/09 18:05:56 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_num_space(int fd)
{
	char	*tmp;
	int		i;

	tmp = get_next_line(fd);
	while (tmp > 0)
	{
		i = 0;
		while (tmp[i] != 0)
		{
			if ((tmp[i] > '9' || tmp[i] < '0') && (tmp[i] != ' '
					&& tmp[i] != '\t' && tmp[i] != '\n' && tmp[i] != '-'))
			{
				close(fd);
				free(tmp);
				return (0);
			}
			i ++;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
	return (1);
}

int	is_val_map(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	else
		return (is_num_space(fd));
}
