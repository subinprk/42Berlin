/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:14:38 by subpark           #+#    #+#             */
/*   Updated: 2023/09/11 14:52:50 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	number_case(t_list *stack_a, t_list *stack_b, t_list *target)
{
	int		mid_a;
	int		mid_b;
	int		tmp;
	int		order_b;
	int		order_a;

	tmp = 0;
	mid_a = ft_lstsize(stack_a) / 2;
	mid_b = ft_lstsize(stack_b) / 2;
	order_a = order_in_stack(stack_a, target->alloc_node);
	order_b = order_in_stack(stack_b, target);
	if (order_b == 0)
		;
	else if (order_b < mid_b)
		tmp = tmp + 1;
	else
		tmp = tmp + 2;
	if (order_a == 0)
		;
	else if (order_a < mid_a)
		tmp = tmp + 1 * 3;
	else
		tmp = tmp + 2 * 3;
	return (tmp);
}

void	to_5(t_list **stack_a, t_list **stack_b, int type)
{
	if (type == 1)
		rb(stack_b);
	else if (type == 2)
		rrb(stack_b);
	else if (type == 3)
		ra(stack_a);
	else if (type == 4)
	{
		ra(stack_a);
		rb(stack_b);
	}
	else if (type == 5)
	{
		ra(stack_a);
		rrb(stack_b);
	}
	return ;
}

void	case_move(t_list **stack_a, t_list **stack_b, t_list *target, int type)
{
	if (type == 0)
		return ;
	else if (type > 0 && type < 6)
		to_5(stack_a, stack_b, type);
	else if (type == 6)
		rra(stack_a);
	else if (type == 7)
	{
		rra(stack_a);
		rb(stack_b);
	}
	else
		rrr(stack_a, stack_b);
	type = number_case(*stack_a, *stack_b, target);
	return (case_move(stack_a, stack_b, target, type));
}

void	make_order_3(t_list **stack_a)
{
	t_list	*highest;
	t_list	*curr;

	curr = *stack_a;
	highest = *stack_a;
	while (curr)
	{
		if (*(int *)curr->content > *(int *)highest->content)
			highest = curr;
		curr = curr->next;
	}
	if (*stack_a == highest)
		ra(stack_a);
	else if ((*stack_a)->next == highest)
		rra(stack_a);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a);
}

void	move(t_list **stack_a, t_list **stack_b)
{
	t_list	*target;
	int		mid_stack_a;
	int		move_type;

	while (*stack_b)
	{
		target = lowest_cost(*stack_a, *stack_b);
		move_type = number_case(*stack_a, *stack_b, target);
		case_move(stack_a, stack_b, target, move_type);
		pa(stack_a, stack_b);
	}
	target = find_smallest(*(stack_a));
	mid_stack_a = ft_lstsize(*stack_a) / 2;
	if (order_in_stack(*stack_a, target) < mid_stack_a)
		while (*stack_a != target)
			ra(stack_a);
	else
		while (*stack_a != target)
			rra(stack_a);
}
