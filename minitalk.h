/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:03:58 by areifoun          #+#    #+#             */
/*   Updated: 2023/02/26 13:11:27 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_c1
{
	char	letter;
	int		counter;
}t_c1;

t_c1	g_clean_data;

void	handler(int sig, siginfo_t *nact, void *oact);
void	re_call(void);
void	sending_byte(int pid, char *message);
void	run(void);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	bit_by_bit(char byte, int pid);
void	error(void);

#endif
