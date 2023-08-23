/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:18:26 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/18 14:18:26 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			j;
	char			*mem;
	unsigned char	i;

	j = 0;
	i = (unsigned char)c;
	if (ft_isascii(i) == 0)
		return (0);
	mem = (char *)s;
	while (j <= ft_strlen(s))
	{
		if (mem[j] == i)
			return (&mem[j]);
		j++;
	}
	return (0);
}
