/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:33:27 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/16 14:05:27 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	ft_receiv(int signal, siginfo_t *info, void *context)
{
	static unsigned char	buff;
	static int				bit;

	(void)context;
	buff |= (signal == SIGUSR2);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd((char)buff, 1);
		if (!buff)
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		buff = 0;
	}
	buff <<= 1;
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = ft_receiv;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		sleep(1);
	return (0);
}
