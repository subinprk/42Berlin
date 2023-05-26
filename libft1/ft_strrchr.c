/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:48:16 by subpark           #+#    #+#             */
/*   Updated: 2023/05/09 15:56:45 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen(s) - 1;
	if (c < 0 || c > 127)
		return ((char *)s);
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (index >= 0)
	{
		if (s[index] == c)
			return((char *)&s[index]);
		index --;
	}
	return (NULL);
}
/*function that find the last appearance of c*/
