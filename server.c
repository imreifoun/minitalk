/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:05:41 by areifoun          #+#    #+#             */
/*   Updated: 2023/02/26 16:04:16 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	re_call(void)
{
	g_clean_data.letter = 0;
	g_clean_data.counter = 0;
}

void	handler(int sig, siginfo_t *nact, void *oact)
{
	static int		client_pid;
	int				bit;

	(void)oact;
	bit = sig - SIGUSR1;
	if (client_pid != nact->si_pid)
	{
		re_call();
		client_pid = nact->si_pid;
	}
	g_clean_data.letter = g_clean_data.letter << 1 | bit;
	g_clean_data.counter++;
	if (g_clean_data.counter == 8)
	{
		write(1, &g_clean_data.letter, 1);
		re_call();
	}
	client_pid = nact->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	re_call();
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = &handler;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
