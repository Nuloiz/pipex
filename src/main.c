/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:50:07 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/31 12:05:58 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc != 5)
		return (ft_printf("Invalid number of arguments"));
	if (!checker_file(argv))
		return (perror("Invalid file name"), 0);
	fd1 = open (argv[1], O_RDONLY);
	fd2 = open (argv[4], O_WRONLY | O_TRUNC | O_CREAT, 00644);
	pipex(argv, envp, fd1, fd2);
	return (0);
}
