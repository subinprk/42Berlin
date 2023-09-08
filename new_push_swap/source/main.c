/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:09:04 by subpark           #+#    #+#             */
/*   Updated: 2023/09/08 13:54:37 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		load_result;
	t_list	*stack_a;
	t_list	*stack_b;

	load_result = load_args(argc, argv, &stack_a);
	stack_b = NULL;
	if (!load_result || !check_multiple(stack_a))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (check_sorted(stack_a) || having_2_case(&stack_a))
	{
		ft_lstclear(&stack_a, free);
		return (0);
	}
	j = 0;
	while (j ++ < load_result - 4)
		pb(&stack_b, &stack_a);
	make_order_3(&stack_a);
	move(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
