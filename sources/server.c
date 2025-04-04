/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:22:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/03/14 13:22:41 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	put_in_array(unsigned char byte, char array[ARG_MAX_LEN],
		int i, int client_pid)
{
	array[i] = byte;
	if (byte == '\0')
	{
		ft_printf(BLUE"%s\n"RESET, array);
		ft_bzero(array, ft_strlen(array));
		kill(client_pid, SIGUSR1);
	}
}

static void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	byte;
	static int				bit;
	static char				array[ARG_MAX_LEN];
	static int				i;
	int						client_pid;

	(void)ucontext;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		byte = byte | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		put_in_array(byte, array, i, client_pid);
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

	ft_printf(GREEN"Server process ID: %d\n"RESET, getpid());
	action.sa_sigaction = handle_signal;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_printf("Error setting SIGUSR1 handler :()");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_printf("Error setting SIGUSR2 handler :()");
	while (1)
		pause();
	return (0);
}
