/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:43:20 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 13:44:35 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	index;
	size_t	length;
	int	copysize;

	index = 0;
	length = ft_strlen(src);
	if (length > size)
		copysize = size;
	else
		copysize = length;
	while (index < copysize - 1)
	{
		dst[index] = src[index];
		index ++;
	}
	dst[index] = 0;
	return (copysize);
}
