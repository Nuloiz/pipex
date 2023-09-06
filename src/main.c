/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:50:07 by nschutz           #+#    #+#             */
/*   Updated: 2023/09/06 10:03:01 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmds	cmds;

	if (!envp)
		return (perror("envp is empty"), 127);
	if (argc != 5)
		return (perror("Invalid number of arguments"), 1);
	if (!checker_file(argv))
		return (perror("Invalid file name"), 127);
	cmds.fd_input = open (argv[1], O_RDONLY);
	if (cmds.fd_input == -1)
		return (perror("1. File open failed"), 127);
	cmds.fd_output = open (argv[4], O_WRONLY | O_TRUNC | O_CREAT, 00644);
	if (cmds.fd_output == -1)
		return (perror("2. File open failed"), 127);
	get_cmds(argv, envp, cmds);
	pipex(cmds);
	return (0);
}
