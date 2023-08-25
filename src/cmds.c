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
	if (!cmds.cmd1 || !cmds.cmd2 || !cmds.path1 || !cmds.path2)
	{
		free_cmds(cmds);
		cmds.failed = 1;
		return (cmds);
	}
	cmds.envp = envp;
	return (cmds);
}

int	cmd_one(t_cmds cmds, int fd1, int *f)
{
	dup2(fd1, STDIN_FILENO);
	dup2(f[1], STDOUT_FILENO);
	close (f[0]);
	if (execve(cmds.path1, cmds.cmd1, cmds.envp) == -1)
	{
		perror("execve");
		free_cmds(cmds);
		close(fd1);
		return (0);
	}
	return (1);
}

int	cmd_two(t_cmds cmds, int fd2, int *f)
{
	dup2(fd2, STDOUT_FILENO);
	dup2(f[0], STDIN_FILENO);
	close (f[1]);
	if (execve(cmds.path2, cmds.cmd2, cmds.envp) == -1)
	{
		perror("execve");
		free_cmds(cmds);
		close(fd2);
		return (0);
	}
	close(fd2);
	return (1);
}
