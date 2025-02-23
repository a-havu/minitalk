/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:22:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/23 13:27:01 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_in_array(unsigned char byte, char array[131072], int i)
{
	array[i] = byte;
	if (byte == '\0')
	{
		ft_printf("\033[91m%s\n\033[0m", array);
		ft_bzero(array, ft_strlen(array));
	}
}

void handle_signal(int sig, siginfo_t *info, void *ucontext)
{
    static unsigned char	byte;
    static int				bit;
	static char				array[131072];
	static int				i;
	int						client_pid;

	(void)ucontext;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
        byte = byte | (1 << (7 - bit)); 
    bit++;
    if (bit == 8)
    {
        put_in_array(byte, array, i);
		i++;
		if (byte == '\0')
			i = 0;
        byte = 0;
        bit = 0;
    }
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;
	
	ft_printf("\033[92mServer process ID: %d\n", getpid());
	ft_printf("Waiting for message...\n");
	action.sa_sigaction = handle_signal;
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
