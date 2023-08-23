/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:44:38 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/18 10:55:46 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	j;
	int				i;

	str = (unsigned char *)b;
	j = (unsigned char)c;
	i = 0;
	while (len > 0)
	{
		str[i] = j;
		i++;
		len--;
	}
	return (str);
}
