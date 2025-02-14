/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:22:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/14 10:20:03 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// "LISTENER"

int	main(void)
{
	ft_printf("%d\n", getpid());
}

// receives a string from  client and prints it - pretty quickly
// is able to receive strings from several clients in a row without needing to restart