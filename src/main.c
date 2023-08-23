/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:50:07 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/22 11:50:07 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*path_i;
	char	*path_c;
	char	**new_path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			path = envp[i] + 4;
			break ;
		}
		i++;
	}
	new_path = ft_split(path, ':');
	i = 0;
	while (new_path)
	{
		path_i = ft_strjoin(new_path[i], "/");
		path_c = ft_strjoin(path_i, cmd);
		free(path_i);
		if (access(path_c, X_OK) == 0)
		{
			free_array(new_path);
			return (path_c);
		}
		free(path_c);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		fd1;
	int		fd2;

	if (argc != 5)
		return (ft_printf("Invalid number of Arguments"));
	cmd = ft_split(argv[2], ' ');
	path = find_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		perror("execve");
		free(path);
		free_array(cmd);
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_WRONLY);
	//pipex(fd1, fd2);
	close (fd1);
	close (fd2);
	free(path);
	free_array(cmd);
	return (0);
}
