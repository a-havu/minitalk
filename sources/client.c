/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:48:43 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/21 14:00:44 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int server_pid, char c)
{
	int	bit;
	int	i;

	bit = 0;
	i = 7;
	while (i >= 0)
	{
		bit = 1 & (c >> i);
		if (bit)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;
	
	if (argc != 3 || !ft_isdigit(argv[1][0]))
	{
		ft_printf("\033[91mError: wrong arguments!\033[0m\n");
		ft_printf("\033[32mThis is the correct format:");
		ft_printf("./client <SERVER PID> <MESSAGE>\n");
		ft_printf("Try again 🌻\033[0m\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	server_pid = ft_atoi(argv[1]);
	while(argv[2][i])
	{
		send_signal(server_pid, argv[2][i]);
		i++;
	}
	send_signal(server_pid, '\n');
}
