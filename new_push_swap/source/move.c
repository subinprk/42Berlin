/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:14:38 by subpark           #+#    #+#             */
/*   Updated: 2023/09/06 17:25:17 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		order_in_stack(t_list *stack, t_list *target)
{
	int		i;
	t_list	*curr;

	curr = stack;
	i = 0;
	while(curr && curr != target)
	{
		i = i + 1;
		curr = curr->next;
	}
	if (curr == target)
		return (i);
	else
		return (-1);
}

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
		tmp = tmp;
	else if (order_b < mid_b)
		tmp = tmp + 1;
	else
		tmp = tmp + 2;
	if (order_a == 0)
		tmp = tmp;
	else if (order_a < mid_a)
		tmp = tmp + 1 * 3;
	else
		tmp = tmp + 2 * 3;
	return (tmp);
}

void	case_move(t_list **stack_a, t_list **stack_b, t_list *target, int move_type)
{
	if (move_type == 0)
		return ;
	else if (move_type == 1)
		rb(stack_b);
	else if (move_type == 2)
		rrb(stack_b);
	else if (move_type == 3)
		ra(stack_a);
	else if (move_type == 4)
	{
		ra(stack_a);
		rb(stack_b);
	}
	else if (move_type == 5)
	{
		ra(stack_a);
		rrb(stack_b);
	}
	else if (move_type == 6)
		rra(stack_a);
	else if (move_type == 7)
	{
		rra(stack_a);
		rb(stack_b);
	}
	else
		rrr(stack_a, stack_b);
	move_type = number_case(*stack_a, *stack_b, target);
	return (case_move(stack_a, stack_b, target, move_type));
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
		//ft_printf("case is : %d\n", move_type);
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