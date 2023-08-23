/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:17:17 by nschutz           #+#    #+#             */
/*   Updated: 2023/06/01 09:52:02 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(unsigned int n)
{
	if (n < 10)
		n = n + 48;
	else
		n = n + 55;
	if (write(1, &n, 1) == -1)
		return (-1);
	return (0);
}

int	ft_printf_hex_upper(unsigned int hex)
{
	int	i;
	int	j;

	i = 1;
	if (hex < 16)
	{
		if (ft_putchar(hex) == -1)
			return (-1);
	}
	else
	{
		j = ft_printf_hex_upper(hex / 16);
		if (j == -1)
			return (-1);
		i = i + j;
		if (ft_putchar(hex % 16) == -1)
			return (-1);
	}
	return (i);
}
