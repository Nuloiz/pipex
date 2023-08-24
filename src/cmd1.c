/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:34:34 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/24 15:21:48 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1(t_cmds cmds, int fd1, int fd2)
{
	dup2(fd1, fd2);
	if (execve(cmds.path1, cmds.cmd1, cmds.envp) == -1)
	{
		perror("execve");
		free_cmds(cmds);
		return ;
	}
}
