#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>

typedef struct state
{
    int c;
    int i;
}            t_state;

void    send_signal(int pid, char c);
void    sig_usr1(int sig);
void    sig_usr2(int sig);

#endif