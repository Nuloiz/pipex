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

void	child_process(t_cmds cmds, int *f, int fd1, int fd2)
{
	pid_t	younger_child;
	pid_t	older_child;

	younger_child = fork();
	if (younger_child == -1)
	{
		perror("fork");
		free_cmds(cmds);
		return ;
	}
	else if (younger_child == 0)
		cmd_one(cmds, fd1, f);
	older_child = fork();
	if (older_child == -1)
	{
		perror("fork");
		free_cmds(cmds);
		return ;
	}
	else if (older_child == 0)
		cmd_two(cmds, fd2, f);
}

void	pipex(char **argv, char **envp, int fd1, int fd2)
{
	t_cmds	cmds;
	int		f[2];

	cmds = get_cmds(argv, envp);
	if (cmds.failed == 1)
		return ;
	pipe(f);
	child_process(cmds, f, fd1, fd2);
	free_cmds(cmds);
}
