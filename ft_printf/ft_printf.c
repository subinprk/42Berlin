/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:01:55 by subpark           #+#    #+#             */
/*   Updated: 2023/06/14 18:19:58 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int afterp(char c, va_list ap)
{
	char *type;

	if (c == 'c')

	else if (c == 's')

	else if (c == 'p')
	else if (c == 'd')
	else if (c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (c == 'X')
	else if (c == '%')
		write(1, "%", 1);
	else
		return (0);
	va_art(ap, );
	return (1);
}
int ft_printf(const char *format, ...)
{
	int i;
	va_list ap;

	va_start(ap, format);
	i = 0;
	while (format[i] != '%')
		write(1, &format[i ++], 1);
	afterp(format[++i], ap);
	

	va_end(ap);
	return (0);
}