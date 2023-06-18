/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:01:55 by subpark           #+#    #+#             */
/*   Updated: 2023/06/18 23:18:28 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printp(char c, va_list ap, int *count)
{
	int	t;

	if (c == 'c')
		t = write(1, ap, 1);
	else if (c == 's')
		t = write4s(ap);
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
	*count = *count + t;//for the return value of printf(total length)
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
	while (format[i] && format[i] != '%')
	{
		count = count + write(1, &format[i ++], 1);
		if (format[i] == '%' && format[(i ++) + 1])
		{
			if (format[i] == '%')
				count = count + write(1, "%", 1);
			else//anyway, run the function.
			{
				if(printp(format[i], ap, &count) <= 0 || afterp(format[i], ap))
					return (-1);//printp와 afterp 순서대로 실행, 에러 발생 시 종료

			}
				return (-1);//error of non listed c, return negative number
		}
	}

	
	va_end(ap);
	return (i + );
}