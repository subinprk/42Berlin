/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:01:55 by subpark           #+#    #+#             */
/*   Updated: 2023/06/19 17:52:22 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printp(char c, va_list ap)
{
	int	t;

	if (c == 'c')
		t = write(1, ap, 1);
	else if (c == 's')
		t = write4s(ap);
	else if (c == 'p')
		t = write4p(ap);
	else if (c == 'd')
		t = write4d(ap);
	else if (c == 'i')
		t = write4d(ap);
	else if (c == 'u')
		t = write4u(ap);
	else if (c == 'x')
		t = write4lhex(ap);
	else if (c == 'X')
		t = write4uhex(ap);
	else
		return (0);
	return (t);
}

int afterp(char c, va_list ap)
{
	if (c == 'c')
		va_arg(ap, char);
	else if (c == 's')
		va_arg(ap, char*);
	else if (c == 'p')
		va_arg(ap, int);
	else if (c == 'd')
		va_arg(ap, int);
	else if (c == 'i')
		va_arg(ap, int);
	else if (c == 'u')
		va_arg(ap, unsigned int);
	else if (c == 'x')
		va_arg(ap, unsigned int);
	else if (c == 'X')
		va_arg(ap, unsigned int);
	else
		return (0);
	return (1);
}

int ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list ap;

	count = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		count = count + write(1, &format[i ++], 1);
		if (format[i] == '%')
		{
			printf("hi\n");
			i ++;
			count = count + printp(format[i], ap);
				if(!afterp(format[i], ap))
					return (-1);
		}
	}
	va_end(ap);
	return (count);
}

int main(){
	ft_printf("hello %d", 10);
	return 0;
}