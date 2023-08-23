/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:16:03 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/30 10:16:03 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(unsigned long long n)
{
	if (n < 10)
		n = n + 48;
	else
		n = n + 87;
	if (write(1, &n, 1) == -1)
		return (-1);
	return (0);
}

static int	ft_printf_hex(unsigned long long n)
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
		j = ft_printf_hex(n / 16);
		if (j == -1)
			return (-1);
		i = i + j;
		if (ft_putchar(n % 16) == -1)
			return (-1);
	}
	return (i);
}

int	ft_printf_void(unsigned long long n)
{
	int	i;

	if (write(1, "0x", 2) == -1)
		return (-1);
	i = ft_printf_hex(n);
	if (i == -1)
		return (-1);
	i = i + 2;
	return (i);
}
