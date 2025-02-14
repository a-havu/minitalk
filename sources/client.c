/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:48:43 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/14 13:22:42 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// "SPEAKER"



int	main(int argc, char **argv)
{
	int	server_pid;
	
	if (argc != 3 || !ft_isdigit(argv[1][0]))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	kill(server_pid, SIGUSR1);
	kill(server_pid, SIGUSR2);
}

// takes two parameters: the server PID &  the string to send !! it can't receive a whole string,
//instead it receives ASCII's in the form of 0's and 1's
// sends the string to the server 