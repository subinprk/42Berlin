/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:28:20 by subpark           #+#    #+#             */
/*   Updated: 2023/10/18 14:41:03 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long	ft_atoe(const char *nptr)
{
	int	num;
	int	index;
	int	sign;

	sign = 1;
	num = 0;
	index = 0;
	while ((nptr[index] != 0 && spc(nptr[index]) == 1))
		index ++;
	if (!ft_memcmp(&nptr[index], "-2147483648", 11))
		return (-2147483648);
	signs(nptr, &index, &sign);
	while (nptr[index] != 0)
	{
		if (nptr[index] < '0' || nptr[index] > '9')
			return (LONG_MIN);
		else if (10 * num + (nptr[index] - '0') < num)
			return (LONG_MIN);
		else
			num = 10 * num + (nptr[index] - '0');
		index ++;
	}
	return (sign * num);
}