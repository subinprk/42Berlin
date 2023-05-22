/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:04 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 16:23:41 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*tmp;

	index = n - 1;
	tmp = (char *)s;
	while (index >= 0)
	{
		if (tmp[index] == c)
			return (&tmp[index]);
		index --;
	}
	return (NULL);
}
/*Function that return the pointer appears last 'c' in s*/
