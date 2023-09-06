/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:00:04 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/23 13:00:04 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_cmds(t_cmds *cmds)
{
	if (cmds->failed == 1 || cmds->failed == 3)
		free_array(cmds->cmd1);
	if (cmds->failed == 1 || cmds->failed == 3)
		free_array(cmds->cmd2);
	if (cmds->path1)
		free(cmds->path1);
	if (cmds->path2)
		free(cmds->path2);
	close(cmds->fd_input);
	close(cmds->fd_output);
}
