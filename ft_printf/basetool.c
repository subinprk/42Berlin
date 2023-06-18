/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basetool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:36:32 by subpark           #+#    #+#             */
/*   Updated: 2023/06/19 01:09:31 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i ++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		index;

	index = 0;
	str = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[index] != 0)
	{
		str[index] = s[index];
		index ++;
	}
	str[index] = 0;
	return (str);
}

char	*add1front(char c, char *str)
{
	char	*tmp;
	int		i;

	tmp = malloc(ft_strlen(str) + 2);
	if (!tmp)
		return (NULL);
	tmp[0] = c;
	i = 0;
	while (tmp[i])
	{
		tmp[1 + i] = str[i];
		i ++;
	}
	tmp[ft_strlen(str) + 1] = '\0';
	return (tmp);
}
char	*makehexa(long num, char *tmp, int i)//tmp should be eof, not null when I have to call it. and i should be 0
{
	char	c;

	if (tmp == NULL)
		return (NULL);
	if (num < 0)
		makehexa(-num, add1front('-', tmp), i + 1);
	else if (num < 16)
	{
		if (num < 10)
			c = num + '0';
		else
			c = num + 'a' - 10;
		//printf("final return was here");
		return (add1front(c, tmp));
	}
	else
	{
		if (num % 16 < 10)
			c = num % 16 + '0';
		else
			c = num % 16 + 'a' - 10;
		makehexa(num / 16, add1front(c, tmp), i + 1);
	}
	printf("%d\n", i);
	if (i != 0)
		free(tmp);
}

int main(){
	char *numstr= makehexa(31, "", 0);
	printf("%s\n", numstr);
	free(numstr);
	return 0;
}
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
