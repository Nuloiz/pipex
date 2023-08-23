/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:08:30 by nschutz           #+#    #+#             */
/*   Updated: 2023/06/01 10:44:26 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_printf_arg(const char *input, va_list printf_list)
{
	int	i;

	i = 0;
	if (input[0] == 'c')
		i = ft_printf_sinchar(va_arg(printf_list, int));
	else if (input[0] == 's')
		i = ft_printf_str(va_arg(printf_list, const char *));
	else if (input[0] == 'p')
		i = ft_printf_void(va_arg(printf_list, unsigned long long));
	else if (input[0] == 'd' || input[0] == 'i')
		i = ft_printf_int(va_arg(printf_list, int));
	else if (input[0] == 'u')
		i = ft_printf_unsigned(va_arg(printf_list, unsigned int));
	else if (input[0] == 'x')
		i = ft_printf_hex_lower(va_arg(printf_list, unsigned int));
	else if (input[0] == 'X')
		i = ft_printf_hex_upper(va_arg(printf_list, unsigned int));
	else if (input[0] == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_printf_dispatcher(const char *input, va_list printf_list)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (input[i] == '%' && input[i + 1])
	{
		if (input[i + 1])
			count = ft_printf_arg(&input[i + 1], printf_list);
	}
	else
		count = ft_putchar(input[i]);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	printf_list;
	int		i;
	int		j;
	int		count;

	va_start(printf_list, input);
	i = 0;
	count = 0;
	if (!input)
		return (0);
	while (input[i] != '\0')
	{
		j = count;
		count = count + ft_printf_dispatcher(&input[i], printf_list);
		if (input[i] == '%' && input[i + 1])
			i++;
		if (count < j)
			return (-1);
		i++;
	}
	va_end(printf_list);
	return (count);
}
