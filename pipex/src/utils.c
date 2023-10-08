/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:33:08 by subpark           #+#    #+#             */
/*   Updated: 2023/10/09 00:12:42 by siun             ###   ########.fr       */
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

char	*path_pointer(char **env, char *command)
{
	char	**path_array;
	char	*path;
	int		i;

	path_array = paths_array(env);
	i = 0;
	while (path_array[i] != NULL)
	{
		if (access(path_array[i], 0) == 0)
		{
			path = ft_strdup(path_array[i]);
			free_2d(path_array);
			return (path);
		}
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

