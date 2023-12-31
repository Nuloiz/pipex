/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:15:50 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/30 10:15:50 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_str(const char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (c[i] != '\0')
	{
		if (write(1, &c[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
