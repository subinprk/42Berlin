/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:43 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 15:48:06 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != c)
	{
		if (s[index] == 0)
			return (NULL);
		index ++;
	}
	return ((char *)&s[index]);
}
/*Function that return the pointer of the first 'c' appearing*/
