/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimalNpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:19:14 by subpark           #+#    #+#             */
/*   Updated: 2023/06/20 14:08:38 by subpark          ###   ########.fr       */
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

char    *makepointer(void *pointer, char *tmp, int i)
{
	char	*str;

	str = makeposhexa((long)pointer, tmp, i);
	str = add1front('x', str, 1);
	str = add1front('0', str, 1);
	return (str);
}
/*
int main(){
	printf("%s\n", makedecimal(-10, "", 0));
}*/