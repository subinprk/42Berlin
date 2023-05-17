/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:46:17 by subpark           #+#    #+#             */
/*   Updated: 2023/05/11 15:07:25 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	countrow(char const *s, char c)
{
	int	tmp;
	int	index;
	int	row;

	index = 0;
	row = 0;
	while (s[index])
	{
		tmp = 0;
		while (s[index] != c && s[index] != 0)
		{
			tmp ++;
			index ++;
		}
		if (s[index] == c && tmp > row)
			row = tmp;
		index ++;
	}
	return (row);
}

int	countcolumn(char const *s, char c)
{
	int	index;
	int	column;

	column = 1;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			column ++;
		index ++;
	}
	return (column);
}

char	**writestr(char const *s, char **str, char c)
{
	int	index;
	int	irow;
	int	icol;

	index = 0;
	irow = 0;
	icol = 0;
	while (s[index])
	{
		if (s[index] == c)
		{
			str[icol][irow] = 0;
			icol ++;
			irow = 0;
		}
		else
		{
			str[icol][irow] = s[index];
			irow ++;
		}
		index ++;
	}
	str[icol][irow] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		row;
	int		column;
	int		tmp;

	row = countrow(s, c);
	column = countcolumn(s, c);
	str = (char **) malloc((column + 1) * sizeof(char *));
	tmp = 0;
	while (tmp < column)
	{
		str[tmp] = (char *) malloc((row + 1) * sizeof(char));
		tmp ++;
	}
	writestr(s, str, c);
	return (str);
}
/*
#include <stdio.h>
int main()
{
	int row = countrow("hello world I'm Subin", ' ');
	int column = countcolumn("hello world I'm Subin", ' ');
	char **str = ft_split("hello world I'm Subin", ' ');
	for(int i = 0; i < column; i++)
		printf("%s\n", str[i]);
	for(int i = 0; i < column; i++)
	{
		free(str[i]);
	}
	free(str);
	return 0;
}*/
