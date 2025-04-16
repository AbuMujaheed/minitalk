/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:02:55 by sojetimi          #+#    #+#             */
/*   Updated: 2025/04/16 11:35:37 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_message(char **msg, size_t *len)
{
	if (*msg)
	{
		write(1, *msg, *len);
		write(1, "\n", 1);
		free(*msg);
		*msg = NULL;
		*len = 0;
	}
}

void	append_char(char **msg, unsigned char c, size_t *len)
{
	char	*new_msg;

	new_msg = malloc(*len + 2);
	if (!new_msg)
		return ;
	if (*msg)
	{
		memcpy(new_msg, *msg, *len);
		free(*msg);
	}
	new_msg[(*len)++] = c;
	new_msg[*len] = '\0';
	*msg = new_msg;
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_byte = 0;
	static int				bit_position = 0;
	static char				*message = NULL;
	static size_t			len = 0;

	(void)context;
	if (sig == SIGUSR1)
		current_byte = (current_byte << 1);
	else if (sig == SIGUSR2)
		current_byte = (current_byte << 1) | 1;
	bit_position++;
	if (bit_position == 8)
	{
		if (current_byte == '\0')
			reset_message(&message, &len);
		else
			append_char(&message, current_byte, &len);
		current_byte = 0;
		bit_position = 0;
	}
	if (info && info->si_pid)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	printf("I am Server and my PID is: %d\n", getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
