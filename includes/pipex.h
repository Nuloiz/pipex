/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:50:20 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/22 12:57:53 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define FUN "/bin/rm"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "../tools/libft/libft.h"

typedef struct s_cmds
{
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	char	**envp;
	int		failed;
	int		fd_input;
	int		fd_output;
}				t_cmds;

int		main(int argc, char **argv, char **envp);
int		checker_file(char **argv);
int		checker_cmd(char **argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	pipex(t_cmds *pipex);
void	get_cmds(char **argv, char **envp, t_cmds *pipex);
void	cmd_one(t_cmds *cmds, int *f);
void	cmd_two(t_cmds *cmds, int *f);
void	free_array(char **array);
void	free_cmds(t_cmds *cmds);

#endif