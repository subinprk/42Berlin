/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:54:12 by subpark           #+#    #+#             */
/*   Updated: 2023/07/17 16:03:54 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	**alloc_array(char ***map)
{
	float	**container;
	int		nodes;

	nodes = sizeof(map) / sizeof(char *);
	*container = ft_calloc (sizeof(float *), nodes);
	container = ft_calloc
}