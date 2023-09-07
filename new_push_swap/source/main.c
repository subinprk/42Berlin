/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:09:04 by subpark           #+#    #+#             */
/*   Updated: 2023/09/07 16:57:25 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
    int 	i;
	int		j;
	int 	loadResult;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*curr;
	t_list	*next;

	loadResult = loadStackFromArgs(argc, argv, &stack_a);
	stack_b = NULL;
	if (!loadResult || !check_multiple(stack_a))
	{
		ft_printf("Error\n");
		return (1);
	}

	j = 0;
	while (j < loadResult - 4)
	{
		pb(&stack_b, &stack_a);
		j++;
	}
	make_order_3(&stack_a);
	move(&stack_a, &stack_b);
	/*	curr = stack_a;
	while (curr)
	{
		ft_printf("result: %d\n", *(int *)curr->content);
		next = curr->next;
		curr = next;
	}*/
	ft_lstclear(&stack_a, free);
	return (0);
}