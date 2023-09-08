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

void	forking(t_cmds *cmds, int *f)
{
	pid_t	younger_child;
	pid_t	older_child;

	younger_child = fork();
	if (younger_child == -1)
	{
		perror("fork");
		free_cmds(cmds);
		exit(1);
	}
	if (younger_child == 0)
		cmd_one(cmds, f);
	older_child = fork();
	if (older_child == -1)
	{
		perror("fork");
		free_cmds(cmds);
		exit(1);
	}
	if (older_child > 0)
		cmd_two(cmds, f);
	close(f[1]);
	close (f[0]);
	free_cmds(cmds);
	waitpid(-1, f, WNOHANG);
}

void	pipex(t_cmds *cmds)
{
	int		f[2];
	int		piping;

	piping = pipe(f);
	if (piping == -1)
	{
		perror("pipe");
		free_cmds(cmds);
		exit(1);
	}
	forking(cmds, f);
}
