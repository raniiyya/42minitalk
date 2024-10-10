/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:35:16 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/21 15:33:45 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_num(int num, int *count)
{
	unsigned int	nbr;

	nbr = num;
	if (num < 0)
	{
		*count += ft_printf_char('-');
		nbr = -num;
	}
	if (nbr == 0)
	{
		*count += ft_printf_char('0');
		return ;
	}
	if (nbr / 10 != 0)
		ft_printf_num(nbr / 10, count);
	*count += ft_printf_char(nbr % 10 + '0');
}
