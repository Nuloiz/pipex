/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_decimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:17:00 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/31 13:03:22 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_putnbr(unsigned int n)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (n == 0)
		i = i + ft_putchar('0');
	else if (n < 10)
		i = i + ft_putchar(n + 48);
	else
	{
		j = ft_putnbr(n / 10);
		if (j == -1)
			return (-1);
		i = i + j;
		j = ft_putchar(n % 10 + 48);
		i++;
	}
	if (j == -1 || i < j)
		return (-1);
	return (i);
}

int	ft_printf_unsigned(unsigned int nbr)
{
	int	i;

	i = ft_putnbr(nbr);
	if (i == -1)
		return (-1);
	return (i);
}
