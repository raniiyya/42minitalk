/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:52:12 by rdavurov          #+#    #+#             */
/*   Updated: 2024/08/01 09:36:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_signal(int pid, char c)
{
    int i = 0;

    while (i < 8)
    {
        if (c & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        c >>= 1;
        usleep(100);
        i++;
    }
}

int main(int ac, char **av) {
    int i = 0;

    if (ac != 3) {
        ft_printf("Use 2 arguments");
        return (0);
    }
    int pid = ft_atoi(av[1]);
    char *str = av[2];
    while (str[i]) {
        send_signal(pid, str[i]);
        i++;
    }
    ft_printf("\n\n");
    return (0);
}