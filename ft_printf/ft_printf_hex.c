/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:23:27 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/21 15:35:13 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int num, bool upper)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		len += ft_printf_hex(num / 16, upper);
		len += ft_printf_hex(num % 16, upper);
	}
	else
	{
		if (num <= 9)
			len += ft_printf_char(num + '0');
		else if (upper)
			len += ft_printf_char(num - 10 + 'A');
		else
			len += ft_printf_char(num - 10 + 'a');
	}
	return (len);
}
