/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:39:43 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/17 11:19:54 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_found(const char *hay, const char *need, int len, int j)
{
	int	i;

	i = 0;
	while (need[i])
	{
		if (need[i] != hay[i] || j == len)
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (!haystack[0])
		return (0);
	if ((int)len < 0)
		len = 65535;
	while (haystack[i] && i < (int)len)
	{
		if (haystack [i] == needle[0])
		{
			if (ft_found(&haystack[i], needle, (int)len, i))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	if ((int)len == i)
		return (0);
	return (0);
}
