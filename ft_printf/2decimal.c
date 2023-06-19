/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2decimal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:19:14 by subpark           #+#    #+#             */
/*   Updated: 2023/06/19 14:49:31 by subpark          ###   ########.fr       */
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
		return (positivdeci(num / 16, add1front(c, tmp, i), i + 1));
	}
}

char	*makedecimal(long num, char *tmp, int i)
{
	if (num < 0)
		return (add1front('-', positivdeci(num, tmp, i), i + 1));
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