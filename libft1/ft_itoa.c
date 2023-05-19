/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:13:30 by subpark           #+#    #+#             */
/*   Updated: 2023/05/11 16:38:19 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

#include <stdlib.h>
#include "libft.h"

int tool4size(int n, int count)
{
    if (n < 0)
        return tool4size(-n, count + 1);
    else if (n < 10)
        return count;
    else
        return tool4size(n / 10, count + 1);
}

char *ft_itoa(int n)
{
    char *str;
    int index;
    int length;

    length = tool4size(n, 1);
    str = (char *)malloc((length + 1) * sizeof(char));
    if (!str)
        return NULL;
    index = 0;
    if (n < 0)
    {
        str[0] = '-';
        n = (-1) * n;
    }
    else if (n == 0)
    {
        str = (char *)malloc(2 * sizeof(char)); // Allocate memory for "0" and null terminator
        if (!str)
            return NULL;
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    while (n > 0)
    {
        str[length - index - 1] = n % 10 + '0';
        n = n / 10;
        index++;
    }
    str[length] = '\0';
    return str;
}
/*
void main()
{
	printf("%d\n", tool4size(0, 1));
	printf("%s", ft_itoa(98764));
}*/
