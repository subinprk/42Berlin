/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimalNpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:19:14 by subpark           #+#    #+#             */
/*   Updated: 2023/06/21 16:46:03 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*positivdeci(long num, char *tmp, int i)
{
	char	c;

	if (tmp == NULL)
		return (NULL);
	if (num < 10)
	{
		c = num + '0';
		return (add1front(c, tmp, i));
	}
	else
	{
		c = num % 10 + '0';
		return (positivdeci(num / 10, add1front(c, tmp, i), i + 1));
	}
}

char	*makedecimal(long num, char *tmp, int i)
{
	if (num < 0)
		return (add1front('-', positivdeci(-num, tmp, i), i + 1));
	else
		return (positivdeci(num, tmp, i));
}

char	*signeddeci(long num, char *tmp, int i)
{
	if (num < 0)
		return (positivdeci(-num, tmp, i));
	else
		return (positivdeci(num, tmp, i));
}

char	*makeposulhexa(unsigned long num, char *tmp, int i)
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

char	*makepointer(void *pointer, char *tmp, int i)
{
	char	*str;

	str = makeposulhexa((unsigned long)pointer, tmp, i);
	str = add1front('x', str, 1);
	str = add1front('0', str, 1);
	return (str);
}
/*
int main(){
	printf("%s\n", makedecimal(-10, "", 0));
}*/