/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:10:21 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/21 19:29:33 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_var(char *str, va_list args, int *count)
{
	if (*str == 'c')
		*count += ft_printf_char(va_arg(args, int));
	else if (*str == 's')
		*count += ft_printf_str(va_arg(args, char *));
	else if (*str == 'i' || *str == 'd')
		ft_printf_num(va_arg(args, int), count);
	else if (*str == 'u')
		ft_printf_undec(va_arg(args, unsigned int), count);
	else if (*str == 'x' || *str == 'X')
		*count += ft_printf_hex(va_arg(args, unsigned int), (*str == 'X'));
	else if (*str == 'p')
		*count += ft_printf_pt(va_arg(args, void *));
	else if (*str == '%')
		*count += ft_printf_char('%');
}

static bool	is_valid(char c)
{
	const char	*valid = "csidupxX%";
	int			i;

	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (true);
		i++;
	}
	return (false);
}

static void	ft_printf_arg(char *str, va_list args, int *count)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (is_valid(*str))
				ft_printf_var(str, args, count);
		}
		else
			*count += ft_printf_char(*str);
		str++;
	}
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	ft_printf_arg(str, args, &count);
	va_end(args);
	return (count);
}
