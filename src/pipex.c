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

static t_cmds	get_cmds(char **argv, char **envp)
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

void	pipex(char **argv, char **envp)
{
	t_cmds	cmds;
	pid_t	pid;
	int		f[2];

	cmds = get_cmds(argv, envp);
	if (cmds.failed == 1)
		return ;
	pipe(f);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free_cmds(cmds);
		return ;
	}
	else if (pid == 0)
	{
	//	cmd1
	}
	else
	{
	//	cmd2
	}
	free_cmds(cmds);
}
