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

char	*strrchr(const char *s, int c)
{
	int		index;
	char	*place;

	index = 0;
	place = NULL;
	while (s[index] != 0)
	{
		if (s[index] == c)
			*place = *(s + index);
		index ++;
	}
	return (place);
}
