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

int	countcolumn(char const *s, char c)
{
	int	tmp;
	int	index;
	int	column;

	index = 0;
	column = 0;
	tmp = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			tmp ++;
			if (s[index + 1] == 0 || s[index + 1] == c)
			{
				if (tmp > column)
					column = tmp;
				tmp = 0;
			}
		}
		index ++;
	}
	return (column);
}

int	countrow(char const *s, char c)
{
	int	index;
	int	row;
	char	prvc;

	row = 0;
	index = 0;
	prvc = 0;

	if (s[index] != c)
		row ++;
	while (s[index])
	{
		if (prvc == c && s[index] != c)
			row ++;
		prvc = s[index];
		index ++;
	}
	return (row);
}

char	**writestr(char const *s, char **str, char c)
{
	int	index;
	int	icol;
	int	irow;

	index = 0;
	icol = 0;
	irow = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			str[irow][icol] = s[index];
			icol ++;
			if (s[index + 1] == '\0' || s[index + 1] == c)
			{
				str[irow][icol] = 0;
				irow ++;
				icol = 0;
			}
		}
		index ++;
	}
	str[irow] = 0;
	return (str);
}

char	**allocate(int row, int column)
{
	int	t;
	int	tmp;
	char	**str;

	str = (char **) malloc((row + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	tmp = 0;
	while (tmp < row)
	{
		str[tmp] = (char *) malloc((column + 1) * sizeof(char));
		if (str[tmp] == NULL)
		{
			t = 0;
			while (t < tmp)
			{
				free(str[t]);
				t ++;
			}
			free(str);
			return (NULL);
		}
		ft_bzero(str[tmp], row);
		tmp ++;
	}
	return (str);
}
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		row;
	int		column;

	column = countcolumn(s, c);
	row = countrow(s, c);
	str = allocate(row, column);
	writestr(s, str, c);
	return (str);
}

#include <stdio.h>
int main()
{
	int row = countrow("  tripouille  42  ", ' ');
	int column = countcolumn("  tripouille  42  ", ' ');
	char **str = ft_split("  tripouille  42  ", ' ');
	printf("%d, %d\n", row, column);
	for(int i = 0; i < row; i++)
		printf("%s\n", str[i]);
	for(int i = 0; i < row; i++)
	{
		free(str[i]);
	}
	free(str);
	return 0;
}
