/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:32:39 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/16 14:00:48 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

int	g_tmp;

static void	check_receiv(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Message received\n", 1);
		exit(1);
	}
	else if (signal == SIGUSR2)
		g_tmp = 1;
}

static void	ft_error(int pid, int sig)
{
	if (sig == 2)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("Bad PID, retry\n", 1);
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Bad PID, retry\n", 1);
			exit(0);
		}
	}
}

static void	ft_send_signal(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_tmp = 0;
		if ((c >> bit) & 1)
			ft_error(pid, 2);
		else
			ft_error(pid, 1);
		bit--;
		while (!g_tmp)
			usleep(1);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3 || ft_strlen(argv[2]) == 0)
	{
		ft_putstr_fd("Error: wrong format", 1);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd("Format: ./client <PID> <message> ", 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	signal(SIGUSR1, check_receiv);
	signal(SIGUSR2, check_receiv);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_send_signal(pid, argv[2][i]);
		i++;
	}
	ft_send_signal(pid, '\0');
	return (0);
}
