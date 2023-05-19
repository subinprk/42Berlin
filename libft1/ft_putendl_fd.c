/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:09:40 by subpark           #+#    #+#             */
/*   Updated: 2023/05/16 14:59:26 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	index;
	char	*tmp;

	tmp = (char *)malloc((ft_strlen(s) + 2) * sizeof(char));
	index = 0;
	while (s[index])
	{
		tmp[index] = s[index];
		index ++;
	}
	tmp[index] = '\n';
	index ++;
	tmp[index] = 0;
	s = tmp;
	write(fd, s, ft_strlen(s));
	return ;
}
