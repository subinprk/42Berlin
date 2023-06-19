/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:25:18 by subpark           #+#    #+#             */
/*   Updated: 2023/06/19 17:59:08 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write4s(char* str)
{
	int t;

	t = 0;
	while(str)
	{
		write(1, &str[t], 1);
		t ++;
	}
	return (t);
}

int	write4p(void *pointer)
{
	char	*p;
	int		t;

	p = makepointer(pointer, "", 0);
	t = write4s(p);
	free(p);
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

int write4u(int	digit)
{
	char	*num;
	int		t;

	num = signeddeci(digit, "", 0);
	t = write4s(num);
	free(num);
	return (t);
}
