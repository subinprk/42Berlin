/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:27:15 by subpark           #+#    #+#             */
/*   Updated: 2023/06/06 17:02:44 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    *get_next_line(int fd);
char    *put_in_buffer(int fd, char *buffer);
char	*ft_strdup(const char *s);
int 	savewithprv(char *((*buff)[3]), int index, int fd);
int	    ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

#endif