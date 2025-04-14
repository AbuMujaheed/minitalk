/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:36:05 by sojetimi          #+#    #+#             */
/*   Updated: 2025/04/14 19:45:51 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	sig_handler(int sig, siginfo_t *info, void *context);
void	reset_message(char **msg, size_t *len);
void	append_char(char **msg, unsigned char c, size_t *len);
void	ack_handler(int sig);
long	ft_atol(const char *s);
void	send_char(pid_t pid, char c);

#endif
