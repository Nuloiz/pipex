/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:26:26 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/25 13:26:26 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c;

	i = 0;
	if (!s)
		return (0);
	c = ft_calloc(ft_strlen(s) + 1, 1);
	if (!c)
		return (0);
	while (i < ft_strlen(s))
	{
		c[i] = f(i, s[i]);
		i++;
	}
	return (c);
}
