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
