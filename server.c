/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:51:53 by rdavurov          #+#    #+#             */
/*   Updated: 2024/08/06 17:06:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_state g_state = {0, 0}; //stores the character being constructed

void    sig_usr1(int sig)
{
    (void)sig;
    g_state.c |= 1 << g_state.i; //sets the bit at position i to 1
    g_state.i++;
    if (g_state.i == 8)
    {
        ft_printf("%c", g_state.c);
        g_state.c = 0; //resets to 0, stores the character being constructed
        g_state.i = 0; //resets to 0, tracks the bit position
    }
}

void    sig_usr2(int sig)
{
    (void)sig;
    g_state.i++; //increments the bit position from 0
    if (g_state.i == 8) //if all 8 bits have been received
    {
        ft_printf("%c", g_state.c); //prints the character
        g_state.c = 0; //resets to 0
        g_state.i = 0;
    }
}

void    setup_signal_handlers(void)
{
    struct sigaction    sa1;
    struct sigaction    sa2;

    sa1.sa_handler = sig_usr1; //when the program receives a SIGUSR1 signal, it will call the sig_usr1 function
    sigemptyset(&sa1.sa_mask); //initializes the signal set to empty, so that no signals are blocked
    sa1.sa_flags = 0; //no flags are set
    sa2.sa_handler = sig_usr2; 
    sigemptyset(&sa2.sa_mask);
    sa2.sa_flags = 0;
    sigaction(SIGUSR1, &sa1, NULL); //sets the signal handler for SIGUSR1 to sa1
    sigaction(SIGUSR2, &sa2, NULL); //sets the signal handler for SIGUSR2 to sa2
}

int main(void) {
    ft_printf("Server PID: %d\n", getpid());
    setup_signal_handlers();
    while (1)
        pause();
    return (0);
}