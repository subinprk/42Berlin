/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:32 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 17:04:07 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*small == '\0' || big == NULL)
		return ((char*)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (small[j] == big[i + j] && i + j < len)
		{
			if (small[j + 1] == '\0')
			{
				return ((char*)big + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/*find and return the pointer that appear the first little*/
