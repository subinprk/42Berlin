/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low16.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:36:32 by subpark           #+#    #+#             */
/*   Updated: 2023/08/30 15:07:58 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

char	*add1front(char c, char *str, int j)
{
	char	*tmp;
	int		i;

	tmp = malloc(ft_strlen(str) + 2);
	if (!tmp)
		return (NULL);
	tmp[0] = c;
	i = 0;
	while (str[i])
	{
		tmp[1 + i] = str[i];
		i ++;
	}
	tmp[ft_strlen(str) + 1] = '\0';
	if (j > 0)
		free(str);
	return (tmp);
}

char	*makeposhexa(long num, char *tmp, int i)
{
	char	c;

	if (tmp == NULL)
		return (NULL);
	if (num < 16)
	{
		if (num < 10)
			c = num + '0';
		else
			c = num + 'a' - 10;
		return (add1front(c, tmp, i));
	}
	else
	{
		if (num % 16 < 10)
			c = num % 16 + '0';
		else
			c = num % 16 + 'a' - 10;
		return (makeposhexa(num / 16, add1front(c, tmp, i), i + 1));
	}
}

char	*makehexa(long num, char *tmp, int i)
{
	if (num < 0)
		return (makeposhexa(0xffffffff + num + 1, tmp, i));
	else
		return (makeposhexa(num, tmp, i));
}
/*
int main(){
	char *numstr;
	numstr = makehexa(257, "", 0);
	printf("%s\n", numstr);
	free(numstr);
	numstr = makehexa(-31, "", 0);
	printf("%s\n", numstr);
	free(numstr);
	return 0;
}*/
/*
char	*makebinary(long num, int i)
{
	static char	*str;

	if (i != 0)
	{
		//tmp = NULL;
		free(str);
		str = malloc(1);
		str[0] = 0;
	}
	if (num < 0)
	{
		str = ft_strdup("-");
		if (!str)
			return (NULL);
		makebinary((-1)* num, i + 1);
	}
	else if (num < 2)
	{
		if (num == 1)
			str = ft_strjoin("1", str);
		else ;
		return (str);
	}
	else
	{
		if (num % 2 == 1)
		{
			str = ft_strjoin("1", str);
			makebinary(num / 2, i + 1);
		}
		else
		{
			str = ft_strjoin("0", str);
			makebinary(num / 2, i + 1);
		}
	}
}

int main()
{
	char *tmp;
	tmp = makebinary(16, 0);
	printf("%s",tmp);
	free(tmp);
}*/
