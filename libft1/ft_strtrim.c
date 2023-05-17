/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:12:39 by subpark           #+#    #+#             */
/*   Updated: 2023/05/11 13:55:15 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	tool4count(char const *s1, char const *set)
{
	int	count;
	int	i1;
	int	i2;

	i1 = 0;
	count = 0;
	while (s1[i1])
	{
		i2 = 0;
		while (set[i2])
		{
			if (s1[i1] == set[i2])
				break ;
			i2 ++;
		}
		if (!set[i2])
			count ++;
		i1 ++;
	}
	return (count);
}

char	*tool4write(char const *s1, char const *set, char *str)
{
	int	count;
	int	i1;
	int	i2;

	i1 = 0;
	count = 0;
	while (s1[i1])
	{
		i2 = 0;
		while (set[i2])
		{
			if (s1[i1] == set[i2])
				break ;
			i2 ++;
		}
		if (!set[i2])
		{
			str[count] = s1[i1];
			count ++;
		}
		i1 ++;
	}
	str[count] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	str = (char *) malloc(tool4count(s1, set) * sizeof(char) + 1);
	return (tool4write(s1, set, str));
}
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strtrim("is it working?"," ?"));
	return(0);
}*/
