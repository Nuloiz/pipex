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
	pid_t	child;

	child = fork();
	if (child == -1)
	{
		perror("fork");
		free_cmds(cmds);
		exit(1);
	}
	if (child == 0)
		cmd_one(cmds, f);
	waitpid(child, NULL, WNOHANG);
	if (child > 0)
		cmd_two(cmds, f);
}

void	pipex(t_cmds *cmds)
{
	int		f[2];
	int		piping;

	piping = pipe(f);
	if (piping == -1)
	{
		perror("pipe");
		exit(1);
	}
	forking(cmds, f);
	free_cmds(cmds);
}
