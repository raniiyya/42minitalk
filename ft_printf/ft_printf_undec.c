/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_undec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:10:23 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/21 15:29:59 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_undec(const unsigned int num, int *count)
{
	if (num == 0)
	{
		*count += ft_printf_char('0');
		return ;
	}
	if (num / 10 != 0)
		ft_printf_num(num / 10, count);
	*count += ft_printf_char(num % 10 + '0');
}
