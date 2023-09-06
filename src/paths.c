/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:42:50 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/25 11:42:50 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **envp)
{
	int		i;

	i = 0;
	if (*envp == NULL)
		return ("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:");
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			return (envp[i] + 4);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*path_i;
	char	*path_c;
	char	**new_path;

	path = get_path(envp);
	if (!path)
		return (NULL);
	new_path = ft_split(path, ':');
	i = 0;
	while (new_path[i])
	{
		path_i = ft_strjoin(new_path[i], "/");
		path_c = ft_strjoin(path_i, cmd);
		free(path_i);
		if (access(path_c, R_OK) == 0)
		{
			free_array(new_path);
			return (path_c);
		}
		free(path_c);
		i++;
	}
	return (free_array(new_path), NULL);
}
