/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:47:31 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 15:25:36 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	lengdst;
	int	index;
	size_t	length;
	int	copysize;

	index = 0;
	lengdst = ft_strlen(dst);
	length = ft_strlen(src);
	if (length < size)
		copysize = length;
	else
		copysize = size;
	while (index < copysize - 1)
	{
		dst[lengdst - 1 + index] = src[index];
		index ++;
	}
	dst[index] = 0;
	return (size);
}

/*function that try to add 'size' bytes of src to the dst
If dst is shorter than the targeted string(part of src),
just do it till it works. But it should be ended with null byte.
return expected size of appending.*/
