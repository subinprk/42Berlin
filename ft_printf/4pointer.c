/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4pointer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:50:25 by subpark           #+#    #+#             */
/*   Updated: 2023/06/19 17:51:09 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *makepointer(void *pointer, char *tmp, int i)
{
	char    *str;
	char	*tmpstr;

	str = makeposhexa((long)pointer, tmp, i);
	str = add1front('x', str, 1);
	str = add1front('0', str, 1);
	return (str);
}
/*
int main(){
	int tmp;
	char *str = makepointer(&tmp, "", 0);
	printf("main %x\n", &tmp);
	printf("main %p\n", &tmp);
	printf("main %d\n", &tmp);
	printf("result %s", str);
	free(str);
	return 0;
}*/