/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:33:08 by subpark           #+#    #+#             */
/*   Updated: 2023/10/05 17:54:19 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i ++]);
	free(arr);
}

char **paths_array(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(&envp[i][ft_strlen("PATH=")], ':'));
		i ++;
	}
	return (NULL);
}

char	*path_pointer(char **env)
{
	char	**path;
	int		i;

	path = paths_array(env);
	i = 0;
	while (path[i] != NULL)
	{
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		i ++;
	}
	return (NULL);
}


/*
void	close_4things(int fd1, int fd2, int fd3, int fd4)
{
	close (fd1);
	close (fd2);
	close (fd3);
	close (fd4);
}*/

