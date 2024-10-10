/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:40:50 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/21 19:18:23 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_hex(unsigned long long int val)
{
	char	tmp[20];
	char	*prefix;
	char	*rest;
	int		i;
	int		len;

	prefix = "0x";
	rest = "0123456789abcdef";
	i = sizeof(tmp) - 2;
	tmp[i + 1] = '\0';
	if (val == 0)
		tmp[i--] = '0';
	while (val > 0 && i >= 0)
	{
		tmp[i--] = rest[val % 16];
		val /= 16;
	}
	write(1, prefix, 2);
	write(1, &tmp[i + 1], sizeof(tmp) - i - 2);
	len = 2 + sizeof(tmp) - i - 2;
	return (len);
}

int	ft_printf_pt(const void *pt)
{
	unsigned long long int	val;
	int						len;

	if (pt == NULL)
		return (write(1, "(nil)", 5));
	val = (unsigned long long int)pt;
	len = ft_write_hex(val);
	return (len);
}
