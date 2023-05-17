/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:48:44 by subpark           #+#    #+#             */
/*   Updated: 2023/05/10 18:15:17 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		index;

	index = 0;
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[index + start] != 0)
	{
		str[index] = s[index + start];
		index ++;
	}
	return (str);
}
