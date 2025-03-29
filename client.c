/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:05:44 by sojetimi          #+#    #+#             */
/*   Updated: 2025/03/29 17:08:41 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long	ft_atol(const char *str)
{
	//qweadsa
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void send_char(int pid, char c)
{
    int i = 7; // Start from MSB (Most Significant Bit)

    while (i >= 0)
    {
        if ((c >> i) & 1) // Check if bit is 1
            kill(pid, SIGUSR2); // Send SIGUSR2 (1)
        else
            kill(pid, SIGUSR1); // Send SIGUSR1 (0)
        
        usleep(100); // Small delay to prevent lost signals
        i--;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i = 0;

    if (argc != 3)
    {
        printf("Usage: ./client <PID> <Message>\n");
        return 1;
    }

    pid = atoi(argv[1]); // Convert PID from string to int

    while (argv[2][i])
    {
        send_char(pid, argv[2][i]); // Send each character
        i++;
    }
	// Send null terminator to indicate end of string
    send_char(pid, '\n'); // Send newline at the end
}
