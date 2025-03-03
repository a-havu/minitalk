/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:48:43 by ahavu             #+#    #+#             */
/*   Updated: 2025/03/03 09:10:13 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_message_received = 0;

static void	ft_error(int num)
{
	if (num == 1)
		ft_printf("\033[91mError: wrong arguments!\033[0m\n");
	if (num == 2)
		ft_printf("\033[91mError: wrong PID!\033[0m\n");
	ft_printf("\033[32mThis is the correct format:");
	ft_printf(" ./client <SERVER PID> <MESSAGE>\n");
	ft_printf("Try again 🌻\033[0m\n");
	exit(EXIT_FAILURE);
}

static void	receive_signal(int sig, siginfo_t *info, void *ucontext)
{
	static int	msg;

	(void)ucontext;
	(void)info;
	if (sig == SIGUSR2)
	{
		msg++;
		g_message_received = 1;
	}
	if (sig == SIGUSR1)
	{
		ft_printf("\033[93m🌸🌸🌸The server confirmed ");
		ft_printf("receiving %d bits from me🥰🌸🌸🌸\n\033[0m", msg);
	}
}

static void	send_signal(int server_pid, char c)
{
	int	bit;
	int	i;

	bit = 0;
	i = 7;
	while (i >= 0)
	{
		bit = 1 & (c >> i);
		if (bit)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_error(2);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_error(2);
		}
		while (g_message_received == 0)
			usleep(100);
		g_message_received = 0;
		i--;
	}
}

static int	check_args(char **argv)
{
	int	i;
	int	ret;
	int	server_pid;

	i = 0;
	ret = 1;
	server_pid = ft_atoi(argv[1]);
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ret = 0;
			break ;
		}
		i++;
	}
	if (server_pid == 0)
		ft_error(2);
	return (ret);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	int					i;
	struct sigaction	receive;

	if (argc != 3 || !check_args(argv))
		ft_error(1);
	i = 0;
	server_pid = ft_atoi(argv[1]);
	receive.sa_sigaction = receive_signal;
	receive.sa_flags = SA_SIGINFO;
	sigemptyset(&receive.sa_mask);
	sigaction(SIGUSR1, &receive, NULL);
	sigaction(SIGUSR2, &receive, NULL);
	while (argv[2][i])
	{
		send_signal(server_pid, argv[2][i]);
		i++;
	}
	send_signal(server_pid, '\0');
}
