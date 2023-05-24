/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:12:19 by subpark           #+#    #+#             */
/*   Updated: 2023/05/10 13:30:55 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	index = 0;
	while (index < n)
	{
		if (*(str1 + index) == *(str2 + index))
			index ++;
		else
			return (str1[index] - str2[index]);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	index;
	int	sign;
	int	countsign;

	sign = 1;
	num = 0;
	index = 0;
	countsign = 0;
	while (nptr[index] != 0)
	{
		if (!ft_memcmp(nptr, "-2147483648", 11))
			return (-2147483648);
		else if (!ft_isdigit(nptr[index - 1]) && (nptr[index] == '\t' 
			|| nptr[index] == '\n' || nptr[index] == ' ' ||
			nptr[index] == '\r'|| nptr[index] == '\v' ||
			nptr[index] == '\f')) ;
		else if (nptr[index] == '-' && countsign ++ == 0)
			sign = (-1) * sign;
		else if (nptr[index] == '+' && countsign ++ == 0) ;
		else if (nptr[index] < '0' || nptr[index] > '9')
			return (sign * num);
		else if (10 * num + (nptr[index] - '0') < num)
			return (0);
		else
			num = 10 * num + (nptr[index] - '0');
		index ++;
	}
	return (sign * num);
}
/*
#include <stdio.h>
void main()
{
	printf("%d \n", atoi("-21474e83648wrf"));
	printf("%d", ft_atoi("-21474e83648wrf"));
}*/
