/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:17:03 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/23 14:17:03 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forking(t_cmds cmds, int *f, int fd1, int fd2)
{
	pid_t	child;

	child = fork();
	if (child == -1)
	{
		perror("fork");
		free_cmds(cmds);
		exit(1);
	}
	if (child == 0)
		cmd_one(cmds, fd1, f);
	waitpid(child, NULL, WNOHANG);
	if (child > 0)
		cmd_two(cmds, fd2, f);
}

void	pipex(char **argv, char **envp, int fd1, int fd2)
{
	t_cmds	cmds;
	int		f[2];
	int		pipex;

	cmds = get_cmds(argv, envp);
	pipex = pipe(f);
	if (pipex == -1)
	{
		perror("pipe");
		exit(1);
	}
	forking(cmds, f, fd1, fd2);
	free_cmds(cmds);
}
