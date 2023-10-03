/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up16.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:28:47 by subpark           #+#    #+#             */
/*   Updated: 2023/06/21 16:43:24 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*makepuphexa(long num, char *tmp, int i)
{
	char	c;

	if (tmp == NULL)
		return (NULL);
	if (num < 16)
	{
		if (num < 10)
			c = num + '0';
		else
			c = num + 'A' - 10;
		return (add1front(c, tmp, i));
	}
	else
	{
		if (num % 16 < 10)
			c = num % 16 + '0';
		else
			c = num % 16 + 'A' - 10;
		return (makepuphexa(num / 16, add1front(c, tmp, i), i + 1));
	}
}

char	*makeuphexa(long num, char *tmp, int i)
{
	if (num < 0)
		return (makepuphexa(0xffffffff + num + 1, tmp, i));
	else
		return (makepuphexa(num, tmp, i));
}

int	write4uhex(long num)
{
	char	*uhex;
	int		t;

	uhex = makeuphexa(num, "", 0);
	t = write4s(uhex);
	free(uhex);
	return (t);
}

int	write4lhex(long num)
{
	char	*uhex;
	int		t;

	uhex = makehexa(num, "", 0);
	t = write4s(uhex);
	free(uhex);
	return (t);
}

/*
int main(){
	char *numstr;
	numstr = makeuphexa(31, "", 0);
	printf("%s\n", numstr);
	free(numstr);
	numstr = makeuphexa(-31, "", 0);
	printf("%s\n", numstr);
	free(numstr);
	printf("%X", -31);
	return 0;
}*/