/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:38:58 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/17 15:20:53 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	char			*mem;
	unsigned char	i;

	i = (unsigned char)c;
	if (ft_isascii(i) == 0)
		return (0);
	mem = (char *)s;
	len = (int)ft_strlen(s);
	while (len >= 0)
	{
		if (mem[len] == i)
			return (&mem[len]);
		len--;
	}
	return (0);
}
