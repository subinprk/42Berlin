/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:46:31 by subpark           #+#    #+#             */
/*   Updated: 2023/10/11 11:16:03 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	path = path_pointer(env, command[0]);
	if (!path)
	{
		free_2d(command);
		free(path);
		return ;
	}
	execve(path, command, env);
	if (path)
		free(path);
	free_2d(command);
}

void	first_action(int *pip, int *pipefd, char *cmd, char **envp)
{
	int	fd[2];

	fd[0] = dup2(pip[0], 0);
	fd[1] = dup2(pipefd[1], 1);
	if (fd[0] == -1 || fd[1] == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(pipefd[0]);
		exit (errno);
		return ;
	}
	close(pipefd[0]);
	exec(cmd, envp);
}

void	second_action(int *pip, int *pipefd, char *cmd, char **envp)
{
	int	fd[2];

	if (pipefd[1] < 0)
		exit(1);
	fd[1] = dup2(pip[1], 1);
	fd[0] = dup2(pipefd[0], 0);
	if (fd[0] == -1 || fd[1] == -1)
	{
		close(fd[1]);
		close(fd[0]);
		close(pipefd[1]);
		exit (errno);
	}
	close(pipefd[1]);
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
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	pip[2];

	if (argc != 5)
	{
		ft_printf("Error: Bad arguments\n");
		exit(1);
	}
	pip[0] = open(argv[1], O_RDONLY);
	pip[1] = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	print_error_cmd(envp, argv[2]);
	print_error_cmd(envp, argv[argc -2]);
	if (pip[0] < 3 || pip[1] < 3)
	{
		if (pip[0] < 0)
			ft_printf("bash: %s: ", argv[1]);
		if (pip[1] < 0)
			ft_printf("bash: %s: ", argv[argc - 1]);
		perror("");
	}
	pipex(pip, argv[2], argv[3], envp);
	return (0);
}
