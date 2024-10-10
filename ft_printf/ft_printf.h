/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:14:40 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/21 16:13:12 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

int		ft_printf(char *str, ...);
int		ft_printf_char(int c);
int		ft_printf_str(char *str);
int		ft_printf_pt(const void *pt);
int		ft_printf_hex(unsigned int num, bool upper);
void	ft_printf_num(int n, int *count);
void	ft_printf_undec(const unsigned int num, int *count);

#endif