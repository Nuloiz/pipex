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
}				t_cmds;


int		main(int argc, char **argv, char **envp);
int		checker_file(char **argv);
int		checker_cmd(char **argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	pipex(char **argv, char **envp, int fd1, int fd2);
void	cmd1(t_cmds cmds, int fd1, int fd2);
void	free_array(char **array);
void	free_cmds(t_cmds cmds);

#endif