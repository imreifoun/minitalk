/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:23:46 by areifoun          #+#    #+#             */
/*   Updated: 2023/02/24 11:40:15 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	run(void)
{
	write(1, "Try : ./client <server-pid> <message>", 38);
}

void	error(void)
{
	write(1, "Problem sending the signal!\n", 29);
	exit(1);
}

void	bit_by_bit(char letter, int pid)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (letter >> i & 1);
		if (bit)
		{
			if (kill(pid, SIGUSR2) == -1)
				error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error();
		}
		usleep(500);
		i--;
	}
}

void	sending_byte(int pid, char *message)
{
	int	i;	

	i = -1;
	while (message[++i])
		bit_by_bit(message[i], pid);
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || ft_atoi(argv[1]) <= 0)
	{
		run();
		exit(0);
	}
	sending_byte(ft_atoi(argv[1]), argv[2]);
	return (0);
}
