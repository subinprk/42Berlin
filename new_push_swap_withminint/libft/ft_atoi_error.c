/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:28:20 by subpark           #+#    #+#             */
/*   Updated: 2023/11/03 22:14:16 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	signn(const char *nptr, int *index, long *sign)
{
	*sign = 1;
	if (nptr[*index] == '-')
		*sign = -1;
	if (nptr[*index] == '+' || nptr[*index] == '-')
		(*index)++;
}

long	ft_atoe(const char *nptr)
{
	long	num;
	int		index;
	long	sign;

	num = 0;
	index = 0;
	while ((nptr[index] != 0 && spc(nptr[index]) == 1))
		index ++;
	if (!ft_memcmp(&nptr[index], "-2147483648", 11))
		return (-2147483648);
	signn(nptr, &index, &sign);
	if (nptr[index] == 0)
		return (LONG_MIN);
	while (nptr[index] != 0)
	{
		if (nptr[index] < '0' || nptr[index] > '9'
			|| 10 * num + (nptr[index] - '0') < num)
			return (LONG_MIN);
		else
			num = 10 * num + (nptr[index] - '0');
		index ++;
	}
	if (sign * num < INT_MAX && sign * num > INT_MIN)
		return (sign * num);
	return (LONG_MIN);
}
