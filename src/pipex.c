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

void	pipex(char **argv, char **envp, int fd1, int fd2)
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
		if (!cmd_one(cmds, fd1, f))
			return ;
	}
	else
	{
		if (cmd_two(cmds, fd2, f))
			return ;
	}
	free_cmds(cmds);
}
