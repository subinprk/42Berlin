/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:46:31 by subpark           #+#    #+#             */
/*   Updated: 2023/10/09 00:12:42 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**command;
	char	*path;

//	printf("hello!");
	command = ft_split(cmd, ' ');
	path = ft_strjoin(path_pointer(env), "/");
	path = ft_strjoin(path, command[0]);
	printf("command path: %s", path);
	if (!path)
	{
		free_2d(command);
		return (perror("command not existing\n"));
	}
	execve(path, command, env);
	printf("\nHi\n");
	free(command);
}

void	first_action(int *pip, int *pipefd, char *cmd, char **envp)
{
	int	fd[2];

	printf("first action\n");
	fd[0] = dup2(pip[0], 0);
	fd[1] = dup2(pipefd[0], 1);
	if (fd[0] == -1 || fd[1] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(pipefd[1]);
		perror("first action dup2");
		exit (1);
	}
	close(pipefd[1]);
	exec(cmd, envp);
}

void	second_action(int *pip, int *pipefd, char *cmd, char **envp)
{
	int fd[2];
	int status;
	printf("second action\n");
//	printf("pipefd[1] : %d\n", pipefd[1]);
//	printf("pip[0]: %d\n", pip[0]);
	fd[1] = dup2(pip[1], 1);;
//	perror("???\n");
	fd[0] = dup2(pipefd[1], 0);
//	ft_printf("pipefd[1] : %d\n", pipefd[1]);
	if (fd[0] == -1 || fd[1] == -1)
	{
		close(fd[1]);
		close(fd[0]);
		close(pipefd[0]);
		perror("second action dup2");
		exit (1);
	}
	close(pipefd[0]);
//	perror("second, waitin first\n");
	wait(&status);
	exec(cmd, envp);
}

void	pipex(int *pip, char *cmd1, char *cmd2, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	else if (pid == 0)
		first_action(pip, pipefd, cmd1, envp);
	else
		second_action(pip, pipefd, cmd2, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int pip[2];

	pip[0] = open(argv[1], O_RDONLY);
	pip[1] = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
//	printf("pip[0]: %d\n", pip[0]);
	if (pip[0] < 3 || pip[1] < 3)
		return (-1);
	pipex(pip, argv[2], argv[3], envp);
	return (0);
}