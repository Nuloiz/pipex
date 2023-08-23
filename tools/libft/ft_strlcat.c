/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:02:56 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/19 10:46:32 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;
	size_t	j;

	d = ft_strlen(dst);
	s = 0;
	i = d;
	j = ft_strlen(src);
	if (dstsize < d || dstsize == 0)
	{
		return (dstsize + ft_strlen(src));
	}
	while (s < j && (dstsize - i) > 1)
	{
		dst[d] = src[s];
		d++;
		s++;
		dstsize--;
	}
	dst[d] = '\0';
	return (ft_strlen(src) + i);
}
