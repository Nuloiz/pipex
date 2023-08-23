/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:17:41 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/31 15:41:29 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(unsigned int n)
{
	if (n < 10)
		n = n + 48;
	else
		n = n + 87;
	if (write(1, &n, 1) == -1)
		return (-1);
	return (0);
}

int	ft_printf_hex_lower(unsigned int n)
{
	int	i;
	int	j;

	i = 1;
	if (n < 16)
	{
		if (ft_putchar(n) == -1)
			return (-1);
	}
	else
	{
		j = ft_printf_hex_lower(n / 16);
		if (j == -1)
			return (-1);
		i = i + j;
		if (ft_putchar(n % 16) == -1)
			return (-1);
	}
	return (i);
}
