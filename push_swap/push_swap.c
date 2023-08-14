/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:34:51 by subpark           #+#    #+#             */
/*   Updated: 2023/08/14 17:32:09 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tmpdel()
{
	return ;
}

void	load_stack(char	*num, t_list **lst)
{
	t_list	*new;
	int		number;

	number = atoi(num);
	new = ft_lstnew(number);
	ft_lstadd_front(lst, new);
}

void	make_order_3(t_list **stack_a)
{
	t_list	*st;
	t_list	*nd;
	t_list	*rd;
	st = *stack_a;
	nd = (*stack_a)->next;
	rd = ((*stack_a)->next)->next;
	printf("1st a: %d\n", st->content);
	printf("2nd a: %d\n", nd->content);
	printf("3rd a: %d\n", rd->content);

	if (st->content < nd->content && st->content < rd->content
		&& rd->content > nd->content && rd->content > st->content)
		return ;
	else if (rd->content < nd->content && rd->content < st->content
		&& nd->content > st->content && nd->content > rd->content)
	{
		rotate_a(stack_a);
		return (make_order_3(stack_a));
	}
	else if (nd->content < rd->content && nd->content < st->content
		&& st->content > nd->content && st->content > rd->content)
	{
		rerotate_a(stack_a);
		return (make_order_3(stack_a));
	}
	else
	{
		swap_a(stack_a);
		return (make_order_3(stack_a));
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*curr;
	t_list	*prv;

	if (argc < 1)
		return(0);
	i = 1;
	while (i < argc)
		load_stack(argv[i ++], &stack_a);
	j = 0;
	while (j < i - 4)
	{
		push_b(&stack_b, &stack_a);
		j ++;
	}
	make_order_3(&stack_a);
//	select_sort(&stack_a, &stack_b);
	curr = stack_a;
	while (curr != NULL)
	{
		printf("%d \n", curr->content);
		prv = curr;
		curr = curr->next;
		free(prv);
	}
	free(curr);
}