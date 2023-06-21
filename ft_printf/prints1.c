/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:25:18 by subpark           #+#    #+#             */
/*   Updated: 2023/06/21 16:47:48 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write4s(char *str)
{
	int	t;

	t = 0;
	if (str == NULL)
		t = write(1, "(null)", 6);
	else
	{
		while (str[t])
		{
			write(1, &str[t], 1);
			t ++;
		}
	}
	return (t);
}

int	write4p(void *pointer)
{
	char	*p;
	int		t;

	if (pointer == NULL)
		t = write(1, "(nil)", 5);
	else
	{
		p = makepointer(pointer, "", 0);
		t = write4s(p);
		free(p);
	}
	return (t);
}

int	write4d(int deci)
{
	char	*d;
	int		t;

	d = makedecimal((long)deci, "", 0);
	t = write4s(d);
	free(d);
	return (t);
}

int	write4u(long digit)
{
	char	*num;
	int		t;

	num = signeddeci(digit, "", 0);
	t = write4s(num);
	free(num);
	return (t);
}
