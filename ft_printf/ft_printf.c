/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:01:55 by subpark           #+#    #+#             */
/*   Updated: 2023/06/20 14:55:55 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printp(char c, va_list ap)
{
	int	t;
	char	tmp;

	if (c == 'c')
	{
		tmp = va_arg(ap, int);
		t = write(1, &tmp, 1);
	}
	else if (c == 's')
		t = write4s(va_arg(ap, char*));
	else if (c == 'p')
		t = write4p(va_arg(ap, void*));
	else if (c == 'd')
		t = write4d(va_arg(ap, int));
	else if (c == 'i')
		t = write4d(va_arg(ap, int));
	else if (c == 'u')
		t = write4u(va_arg(ap, unsigned int));
	else if (c == 'x')
		t = write4lhex(va_arg(ap, int));
	else if (c == 'X')
		t = write4uhex(va_arg(ap, int));
	else
		return (0);
	return (t);
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
			if (format[++ i] == '%')
				write (1, "%%", 1);
			else
				count = count + printp(format[i ++], ap);
		}
	}
	va_end(ap);
	return (count);
}

int main(){
	int tmp = -10;
	ft_printf("hello %X%%world %c %s\n", tmp, '!', "I'm subin");
	printf("%X%% world\n", tmp);
	return 0;
}