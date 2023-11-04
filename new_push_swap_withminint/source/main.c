/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:09:04 by subpark           #+#    #+#             */
/*   Updated: 2023/11/03 22:14:51 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_checking(long load_result, t_list *stack_a)
{
	if ((load_result == LONG_MIN || !check_multiple(stack_a)))
	{
		ft_printf("Error\n");
		ft_lstclear(&stack_a, free);
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int			j;
	long		load_result;
	t_list		*stack_a;
	t_list		*stack_b;

	load_result = load_args(argc, argv, &stack_a);
	stack_b = NULL;
	if (load_result == LONG_MIN && ft_printf("Error\n"))
		return (1);
	else if (argc == 1 || argv[1][0] == 0 || stack_a == NULL
			|| !stack_checking(load_result, stack_a))
		return (0);
	else if (check_sorted(stack_a) || having_2_case(&stack_a))
	{
		ft_lstclear(&stack_a, free);
		return (0);
	}
	j = 0;
	while (j ++ < load_result - 3)
		pb(&stack_b, &stack_a);
	make_order_3(&stack_a);
	move(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
