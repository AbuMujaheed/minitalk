#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static long	ft_atol(const char *str);
void handle_signal(int signal);
void send_char(int pid, char c);

#endif
