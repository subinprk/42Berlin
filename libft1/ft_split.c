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
	char	prvc;
	int		index;
	int		row;

	row = 0;
	index = 0;
	prvc = 0;
	if (s[index] != c && s[index] != 0)
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
				str[irow][icol] = '\0';
				irow ++;
				icol = 0;
			}
		}
		index ++;
	}
	return (str);
}

char	**free4error(char **str, int tmp)
{
	int	t;

	t = 0;
	while (t < tmp)
		free(str[t ++]);
	free(str);
	return (NULL);
}

char	**allocate(int row, char const *s, int c)
{
	char	**str;
	int		i;
	int		tmp;
	int		j;

	str = (char **) malloc((row + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	tmp = 0;
	i = 0;
	while (tmp < row)
	{
		j = 0;
		while (s[i] == c && s[i] != 0)
			i ++;
		while (s [i + j] != c && s[i + j] != 0)
			j ++;
		if (j != 0)
		{
			str[tmp] = (char *) malloc((j + 1) * sizeof(char));
			ft_bzero(str[tmp], j + 1);
			i = i + j;
		}
		if (j != 0 && str[tmp] == NULL)
		{
			free4error(str, tmp);
			return (NULL);
		}
		tmp ++;
	}
	str[tmp] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		row;

	row = countrow(s, c);
	str = allocate(row, s, c);
	if (!str)
		return (NULL);
	writestr(s, str, c);
	return (str);
}
/*
#include <mcheck.h>
#include <stdio.h>
int main()
{
	//int row = countrow("", ' ');
	//int column = countcolumn("", ' ');
	int	i;
	char **str = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. 
	Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, 
	ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, 
	varius a, semper congue, euismod non, mi.", '\0');
	//printf("%d\n", row);
	for(i = 0; str[i] != NULL; i++)
		printf("%s\n", str[i]);
	//mcheck(str[1]);
	for(i = 0; str[i] != NULL; i++)
		free(str[i]);
	free(str[i]);
	free(str);
	return 0;
}*/
