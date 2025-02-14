/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:22:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/14 13:50:50 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// "LISTENER"

void	function_to_be_applied(int signum)
{
	if (signum == SIGUSR1)
		// do stuff
	else if (signum == SIGUSR2)
		// do other stuff
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &function_to_be_applied, NULL);
		sigaction(SIGUSR2, &function_to_be_applied, NULL);
	}
}

// receives a string from  client and prints it - pretty quickly
// is able to receive strings from several clients in a row without needing to restart