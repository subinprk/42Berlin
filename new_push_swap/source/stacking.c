/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:10:37 by subpark           #+#    #+#             */
/*   Updated: 2023/09/07 17:19:33 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	load_stack(char	*num, t_list **lst)
{
	t_list	*new;
	int		*number;

	number = (int *)malloc(sizeof(int));
	if (!number)
	{
		ft_lstclear(lst, free);
		return (0);
	}
	*number = ft_atoi(num);
	if ((*number) == 0)
	{
		ft_lstclear(lst, free);
		free(number);
		return (0);
	}
	new = ft_lstnew(number);
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstadd_front(lst, new);
	return (1);
}

void	freeing_array(char **splited, int *number)
{
	int	i;

	i = 0;
	while (splited[i])
		free(splited[i ++]);
	free(splited);
	if (number)
		free(number);
}

void	generate_new_node(int *number, t_list **lst)
{
	t_list	*new;
	new = ft_lstnew(number);
	if (*lst == NULL)
			*lst = new;
	else
		ft_lstadd_front(lst, new);
}

int	load_stack_one(char *str, t_list **lst)
{
	int *number;
	int	i;
	int	j;
	char	**splited;

	splited = ft_split(str, ' ');
	i = 0;
	while (splited[i])
		i ++;
	j = i;
	while (0 < j)
	{
		number = (int *)malloc(sizeof(int));
		*number = ft_atoi(splited[j - 1]);
		if (!number | !(*number))
		{
			freeing_array(splited, number);
			ft_lstclear(lst, free);
			return (0);
		}
		generate_new_node(number, lst);
		j --;
	}
	freeing_array(splited, NULL);
	return (i + 1);
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

int loadStackFromArgs(int argc, char **argv, t_list **stack_a)
{
	int i;
	int	tmp;

	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (0);
	*stack_a = NULL;
	if (argc == 2)
	{
		tmp = load_stack_one(argv[1], stack_a);
		if (!tmp)
			return (0);
		else
			return (tmp);
	}
	else
	{
		i = argc - 1;
		while (0 < i)
			if (!load_stack(argv[i --], stack_a))
				return (0);
		return (argc - 1);
	}
}

int	check_multiple(t_list *stack)
{
	t_list	*all;
	t_list	*check;

	check = stack;
	while (check)
	{
		all = check->next;
		while (all)
		{
			if (*(int *)all->content == *(int *)check->content)
				return (0);
			all = all->next;
		}
		check = check->next;
	}
	return (1);
}

/*
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
	if (loadResult == 0)
		return 0;
	else if (loadResult && !check_multiple(stack_a))
	{
		ft_printf("Error\n");
		return 1;
	}
	j = 0;
	while (j < loadResult - 4)
	{
		pb(&stack_b, &stack_a);
		j++;
	}
	make_order_3(&stack_a);
			curr = stack_a;
	while (curr)
	{
		ft_printf("b4 order3: %d\n", *(int *)curr->content);
		next = curr->next;
		curr = next;
	}
	select_sort(&stack_a, &stack_b);
		curr = stack_a;
	while (curr)
	{
		ft_printf("stack a: %d\n", *(int *)curr->content);
		next = curr->next;
		curr = next;
	}
	ft_lstclear(&stack_a, free);
	return 0;
}*/