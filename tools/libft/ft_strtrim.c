/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:49:21 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/23 12:49:21 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strchar(const char *set, char s, size_t len)
{
	size_t	pos;

	pos = 0;
	while (pos < len)
	{
		if (set[pos] == s)
			return (1);
		pos++;
	}
	return (0);
}

size_t	ft_strlenend(const char *s1, const char *set, size_t len)
{
	while (ft_strchar(set, s1[len], ft_strlen(set) + 1) && len > 0)
	{
		len--;
	}
	return ((int)len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return ((char *)s1);
	while (ft_strchar(set, s1[i], ft_strlen(set)))
	{
		i++;
	}
	if (i >= ft_strlenend(s1, set, ft_strlen(s1) - i) || !*s1)
		return (ft_strdup(""));
	cpy = (char *)ft_calloc(ft_strlenend(s1, set, ft_strlen(s1)) - i + 1, 1);
	if (!cpy)
		return (0);
	while (s1[i] && i < ft_strlenend(s1, set, ft_strlen(s1)))
	{
		cpy[j] = s1[i];
		i++;
		j++;
	}
	return (cpy);
}
