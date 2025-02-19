/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:22:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/19 13:53:50 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_in_array(unsigned char byte, char array[131072], int i)
{
	array[i] = byte;
	if (byte == '\n')
	{
		ft_printf("%s\n", array);
		array = NULL;
		i = 0;
	}
}

void handle_signal(int signum)
{
    static unsigned char	byte;
    static int				bit;
	static char				array[131072];
	static int				i;

    if (signum == SIGUSR1)
        byte = (byte << 1) | 1;
    else if (signum == SIGUSR2)
        byte = byte << 1;
    bit++;
    if (bit == 8 && byte)
    {
        put_in_array(byte, array, i);
		i++;
        byte = 0;
        bit = 0;
    }
}

int	main(void)
{
	struct sigaction	action;
	
	ft_printf("\033[92mServer process ID: %d\n", getpid());
	ft_printf("Waiting for message...\n");
	action.sa_handler = handle_signal;
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
