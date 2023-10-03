/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:54:58 by subpark           #+#    #+#             */
/*   Updated: 2023/06/21 16:48:50 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(const char *s);
char	*add1front(char c, char *str, int j);
char	*makeposhexa(long num, char *tmp, int i);
char	*makehexa(long num, char *tmp, int i);
char	*makepuphexa(long num, char *tmp, int i);
char	*makeuphexa(long num, char *tmp, int i);
char	*makepointer(void *pointer, char *tmp, int i);
char	*makedecimal(long num, char *tmp, int i);
char	*signeddeci(long num, char *tmp, int i);
char	*positivdeci(long num, char *tmp, int i);
int		write4s(char *str);
int		write4uhex(long num);
int		write4lhex(long num);
int		write4p(void *pointer);
int		write4d(int deci);
int		write4u(long digit);
int		printp(char c, va_list ap);
char	*makeposulhexa(unsigned long num, char *tmp, int i);
int		ft_printf(const char *format, ...);

#endif