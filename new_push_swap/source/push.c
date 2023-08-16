/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:36:00 by subpark           #+#    #+#             */
/*   Updated: 2023/08/16 15:46:42 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int push(t_list **origin, t_list **target)
{
	t_list	*head_origin;
	t_list	*head_target;
	
	if (!origin)
		return (-1);
	head_origin = *origin;
	head_target = *target;
	*origin = (*origin)->next;
	head_origin->next = head_target;
	*target = head_origin;
}