/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:50:50 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/19 12:50:50 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	i;

	s = 0;
	i = ft_strlen(src);
	if (dstsize == 0)
	{
		return (i);
	}
	while (s < i && (dstsize) > 1)
	{
		dst[s] = src[s];
		s++;
		dstsize--;
	}
	dst[s] = '\0';
	return (i);
}
