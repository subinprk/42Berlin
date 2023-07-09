/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:04:02 by subpark           #+#    #+#             */
/*   Updated: 2023/07/10 00:08:51 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	tmpdel();
int		ft_lstsize(t_list *lst);
void	connect(t_list **a, t_list *new);
void	push(t_list **a, t_list **b);
void	swap(t_list **a);
void	sswap(t_list **a, t_list **b);
void	rotate(t_list **a);
void	rotaterotate(t_list **a, t_list **b);
void	rerotate(t_list **a);
void	reroro(t_list **a, t_list **b);
int		spc(char c);
void	signs(const char *nptr, int *index, int *sign);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
t_list  *point_list(t_list *stack, int num);
t_list  *choicepivot(t_list *stack);
void    push_swap(int argc, char **argv);


#endif