/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:42:21 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/24 10:42:37 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	checker_file(char **argv)
{
	int	fd1;
	int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		return (0);
	fd2 = open(argv[4], O_WRONLY);
	if (fd2 < 0)
	{
		close (fd1);
		return (0);
	}
	close (fd1);
	close (fd2);
	return (1);
}

static char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			path = envp[i] + 4;
			break ;
		}
		i++;
	}
	return (path);
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
	while (new_path)
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
	return (NULL);
}

int	checker_cmd(char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[2], ' ');
	path = find_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_array(cmd);
		return (0);
	}
	free(path);
	free_array(cmd);
	cmd = ft_split(argv[3], ' ');
	path = find_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_array(cmd);
		return (0);
	}
	free(path);
	free_array(cmd);
	return (1);
}
