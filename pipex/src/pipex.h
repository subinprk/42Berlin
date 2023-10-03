/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:33:24 by subpark           #+#    #+#             */
/*   Updated: 2023/10/03 17:52:56 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	pipex(int *pip, char *cmd1, char *cmd2, char **envp);
int 	first_action(int *pip, int *pipefd, char *cmd, char **envp);
int 	second_action(int *pip, int *pipefd, char *cmd, char **envp);
void	exec(char *cmd, char **env);

#endif