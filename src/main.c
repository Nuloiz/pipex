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
	int	fd1;
	int	fd2;

	if (!envp)
		return (perror("envp is empty"), 127);
	if (argc != 5)
		return (perror("Invalid number of arguments"), 1);
	if (!checker_file(argv))
		return (perror("Invalid file name"), 127);
	fd1 = open (argv[1], O_RDONLY);
	if (fd1 == -1)
		return (perror("1. File open failed"), 127);
	fd2 = open (argv[4], O_WRONLY | O_TRUNC | O_CREAT, 00644);
	if (fd2 == -1)
		return (perror("2. File open failed"), 127);
	pipex(argv, envp, fd1, fd2);
	return (0);
}
