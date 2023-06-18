/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:25:18 by subpark           #+#    #+#             */
/*   Updated: 2023/06/17 02:13:05 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write4s(char* str)
{
	int t;

	t = 0;
	while(str)
	{
		write(1, str[t], 1);
		t ++;
	}
	return (t);
}

int	write4p(int pointer)
{
	
}

int	write4d(int digit)
{
	if (digit < 10)
	{
		t ++;
		return ();
	}
}