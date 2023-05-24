/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_ft_strtrim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:07:11 by subpark           #+#    #+#             */
/*   Updated: 2023/05/23 12:58:27 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i ++;
	return (i);
}

int	check_set(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (s1[i] != 0)
	{
		j = 0;
		while (s1[i + j] == set[j] && set[j] != 0)
			j ++;
		if (set[j] == 0)
			count = count + 1;
		i ++;
	}
	return (count);
}

char *write_trim_str(char const *s1, char const *set, char *str)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	while (s1[i] != 0)
	{
		j = 0;
		while (s1[i + j] == set[j] && set[j] != 0)
			j ++;
		if (set[j] == 0)
			i = i + ft_strlen(set);
		else
		{
			str[tmp] = s1[i];
			tmp = tmp + 1;
			i = i + 1;
		}
	}
	str[tmp] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s1) - check_set(s1, set) + 1);
	str = write_trim_str(s1, set, str);
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char *str = ft_strtrim("Hello World! Hello world!", "lo");
	printf("%s", str);
	free(str);
	return (0);
}*/
