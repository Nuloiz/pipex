/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:39:08 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/17 12:16:55 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	int		i;
	char	*mem;
	char	loc;

	i = 0;
	mem = (char *)s;
	loc = (char)c;
	while (n > 0)
	{
		if (mem[i] == loc)
			return (&mem[i]);
		i++;
		n--;
	}
	return (0);
}
