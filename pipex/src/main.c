/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:46:31 by subpark           #+#    #+#             */
/*   Updated: 2023/10/05 17:53:36 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**command;

	command = ft_split(cmd, ' ');
	if (!path_pointer(env))
		return (perror("command not existing\n"));
	execve(cmd, paths_arry(env), env);
}

int	first_action(int *pip, int *pipefd, char *cmd, char **envp)
{
	int	fd[2];

	fd[0] = dup2(pip[0], 0);
	fd[1] = dup2(pipefd[0], 1);
	if (fd[0] == 0 || fd[1] == 1)
	{
		perror("first action dup2\n");
		return (0);
	}
	close(pipefd[1]);

	return (1);
}

int	second_action(int *pip, int *pipefd, char *cmd, char **envp)
{
	int fd[2];

	fd[1] = dup2(pip[1], 1);
	fd[0] = dup2(pipefd[1], 0);
	if (fd[0] == 0 || fd[1] == 1)
	{
		perror("first action dup2\n");
		return (0);
	}
	close(pipefd[0]);

	return (1);
}

void	pipex(int *pip, char *cmd1, char *cmd2, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = folk();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
		if (!first_action(pip, pipefd, cmd1, envp))
			return (perror("First cmd"));
	else
		if (!second_action(pip, pipefd, cmd2, envp))
			return (perror("Second cmd"));
}

int	main(int argc, char **argv, char **envp)
{
	int pip[2];

	pip[0] = open(argv[1], O_RDONLY);
	pip[1] = open(argv[argc], O_WRONLY);
	if (!(pip[0] && pip[1]))
		return (-1);
	pipex(pip, argv[2], argv[3], envp);
	return (0);
}