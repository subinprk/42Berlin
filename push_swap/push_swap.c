/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:34:51 by subpark           #+#    #+#             */
/*   Updated: 2023/06/29 00:29:02 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *point_list(t_list *stack, int num)
{
	while (num > 0)
	{
		stack = stack->next;
		num --;
	}
	return (stack);
}

t_list  *choicepivot(t_list *stack)
{
	int		midpoint;
	t_list	*mid1;
	t_list	*mid2;
	t_list	*mid3;

	if (ft_lstsize(stack) < 3)
		return (stack);
	midpoint = ft_lstsize(stack) / 2;
	mid1 = point_list(stack, midpoint - 1);
	mid2 = point_list(stack, midpoint);
	mid3 = point_list(stack, midpoint + 1);
	if ((mid1 <= mid2) * !(mid3 < mid2) + !(mid1 < mid2) *(mid3 <= mid2))
		return (mid2);
	else if ((mid2 <= mid1) * !(mid3 < mid1) + !(mid2 < mid1) *(mid3 <= mid1))
		return (mid1);
	else
		return (mid3);
}

void    push_swap()