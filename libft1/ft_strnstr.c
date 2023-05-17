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

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i1;
	size_t	i2;
	char	*tmp;

	tmp = NULL;
	i1 = 0;
	while (big[i1] != 0 || i1 < len)
	{
		i2 = 0;
		while (little[i2] != 0 || big[i1] != 0 || i1 < len)
		{
			if (big[i1 + i2] == little[i2])
				i2 ++;
			else
				break ;
		}
		if (little[i2] == 0)
		{
			*tmp = big[i1];
			return (tmp);
		}
		i1 ++;
	}
	return (NULL);
}
/*find and return the pointer that appear the first little*/
