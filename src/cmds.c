/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:34:34 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/24 15:57:45 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmds	get_cmds(char **argv, char **envp)
{
	t_cmds	cmds;

	cmds.failed = 0;
	cmds.cmd1 = ft_split(argv[2], ' ');
	cmds.cmd2 = ft_split(argv[3], ' ');
	cmds.path1 = find_path(cmds.cmd1[0], envp);
	cmds.path2 = find_path(cmds.cmd2[0], envp);
	if (!cmds.cmd1 && !cmds.cmd2)
		cmds.failed = 3;
	else if (!cmds.cmd1)
		cmds.failed = 1;
	else if (!cmds.cmd2)
		cmds.failed = 2;
	else
		cmds.failed = 0;
	cmds.envp = envp;
	return (cmds);
}

void	cmd_one(t_cmds cmds, int fd1, int *f)
{
	if (dup2(fd1, STDIN_FILENO) == -1 || dup2(f[1], STDOUT_FILENO) == -1)
	{
		close (f[0]);
		close (fd1);
		perror("dup");
		free_cmds(cmds);
		exit(1);
	}
	close (f[0]);
	if (!cmds.path1 || execve(cmds.path1, cmds.cmd1, cmds.envp) == -1)
	{
		perror("execve");
		free_cmds(cmds);
		close(fd1);
		exit(1);
	}
	close (fd1);
}

void	cmd_two(t_cmds cmds, int fd2, int *f)
{
	if (dup2(fd2, STDOUT_FILENO) == -1 || dup2(f[0], STDIN_FILENO) == -1)
	{
		close (f[1]);
		close (fd2);
		perror("dup");
		free_cmds(cmds);
		exit(1);
	}
	close (f[1]);
	close (fd2);
	if (!cmds.path2 || execve(cmds.path2, cmds.cmd2, cmds.envp) == -1)
	{
		perror("execve");
		free_cmds(cmds);
		exit(1);
	}
}
