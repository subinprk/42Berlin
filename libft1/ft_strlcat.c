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
	size_t	index;
	size_t	eod;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index = 0;
	while(dst[index] != 0 && index < size - 1)
		index ++;
	eod = index;
	while(index < size - 1)
	{
		dst[index] = src[index - eod];
		index ++;
	}
	dst[index] = 0;
	if (dest_len < size)
		return src_len + dest_len;
	else
		return src_len + size;
}

/*function that try to add 'size' bytes of src to the dst
If dst is shorter than the targeted string(part of src),
just do it till it works. But it should be ended with null byte.
return expected size of appending.*/
