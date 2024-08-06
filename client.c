/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:52:12 by rdavurov          #+#    #+#             */
/*   Updated: 2024/08/06 06:10:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_signal(int pid, char c)
{
    int i = 0;

    while (i < 8) //each character is 8 bits since the char in the computer is 8 bits
    {
        if (c & 1)
            kill(pid, SIGUSR1); //if the last bit is 1, send SIGUSR1
        else
            kill(pid, SIGUSR2); //if the last bit is 0, send SIGUSR2
        c >>= 1; //shift the bits to the right
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
    int pid = ft_atoi(av[1]); //converting the first argument to a pid  
    char *str = av[2]; //the second argument is the string to send
    while (str[i]) {
        send_signal(pid, str[i]);
        i++;
    }
    ft_printf("\n\n");
    return (0);
}