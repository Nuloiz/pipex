/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:40:48 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/25 11:32:23 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_placeint(int i, int j, int k)
{
	char	*c;

	c = (char *)ft_calloc(i + 1, 1);
	if (!c)
		return (0);
	while (i > 1)
	{
		i--;
		c[i] = (char)(j % (10) + 48);
		j = j / 10;
	}
	if (k == 1)
		c[0] = '-';
	else
		c[0] = (char)(j % (10) + 48);
	return (c);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		i++;
		k = 1;
		n = n * -1;
	}
	else if (n == 0)
		i++;
	j = n;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (ft_placeint(i, j, k));
}
