/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:05:55 by sojetimi          #+#    #+#             */
/*   Updated: 2025/03/29 16:06:50 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int signal)
{
    static char c;
    static int bit_index;

	char = 0;
	bit_index = 0;

    if (signal == SIGUSR1)
        c = (c << 1) | 0; // Append 0
    else if (signal == SIGUSR2)
        c = (c << 1) | 1; // Append 1

    bit_index++;

    if (bit_index == 8) // If we have 8 bits (1 byte)
    {
        write(1, &c, 1); // Print the character
        bit_index = 0;  // Reset for the next character
        c = 0;          // Reset char storage
    }
}

int main(void)
{
    struct sigaction sa;
    
    printf("Server PID: %d\n", getpid());

    sa.sa_handler = &handle_signal;
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1) // Keep the server running
        pause(); // Wait for signals
}
