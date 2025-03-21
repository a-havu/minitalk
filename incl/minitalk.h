/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:23:13 by ahavu             #+#    #+#             */
/*   Updated: 2025/03/14 13:29:55 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# ifndef ARG_MAX_LEN
#  define ARG_MAX_LEN 131072
# endif

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[36m"
# define RESET "\033[0m"

# include <unistd.h>
# include <signal.h> 
# include "libft_plus.h"
# include "libftprintf.h"

#endif
