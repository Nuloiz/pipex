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

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (ft_printf("Invalid number of arguments"));
	if (!checker_file(argv))
		return (ft_printf("Invalid file names"));
	if (!checker_cmd(argv, envp))
		return (ft_printf("Invalid commands"));
	pipex(argv, envp);
	return (0);
}
