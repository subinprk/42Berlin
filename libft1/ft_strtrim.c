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

int	tool4count(const char *s1, const char *set)
{
	int	count;
	int	setlen;
	int	i1;

	setlen = ft_strlen(set);
	count = 0;
	i1 = 0;
	while (s1[i1] != 0)
	{
		if (ft_strncmp(s1 + i1, set, setlen))
			i1 = i1 + setlen;
		else
		{
			count ++;
			i1 ++;
		}
	}
	return (count);
}

char	*tool4write(const char *s1, const char *set, char *str)
{
	int	index;
	int	setlen;
	int	i1;

	setlen = ft_strlen(set);
	index = 0;
	i1 = 0;
	while (s1[i1])
	{
		if (ft_strncmp(s1 + i1, set, setlen))
			i1 = i1 + strlen;
		else
		{
			str[index] = s1[i1];
			i1 ++;
			index ++;
		}
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	str = (char *) malloc(tool4count(s1, set) * sizeof(char) + 1);
	return (tool4write(s1, set, str));
}

#include <stdio.h>
int main()
{
	printf("%s", ft_strtrim("is it working?"," g?"));
	return(0);
}
