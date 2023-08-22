/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:23:49 by siun              #+#    #+#             */
/*   Updated: 2023/08/19 00:37:22 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int rerotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (stack == NULL || *stack == NULL)
		return (0);
	head = *stack;
	last = ft_lstlast(*stack);
	*stack = last;
	last->next = head;
}

int main() {
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    node1->content = "Node 1";
    node2->content = "Node 2";
    node3->content = "Node 3";

    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    t_list *stack = node1;

    printf("Before rerotate:\n");
    t_list *current = stack;
    do {
        printf("%s\n", (char *)current->content);
        current = current->next;
    } while (current != stack);

    rerotate(&stack);

    printf("\nAfter rerotate:\n");
    current = stack;
    do {
        printf("%s\n", (char *)current->content);
        current = current->next;
    } while (current != stack);

    return 0;
}
