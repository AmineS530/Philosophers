/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:57:59 by asadik            #+#    #+#             */
/*   Updated: 2023/04/01 00:50:19 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

long	ft_time(void)
{
	long			ayaya;
	struct timeval	ze_time;

	gettimeofday(&ze_time, NULL);
	ayaya = (ze_time.tv_sec * 1000) + (ze_time.tv_sec / 1000);
	return (ayaya);
}

long	time_stamp(t_philosopher *the_time)
{
	long	time_currently;

	time_currently = ft_time() - the_time->philo_creation_time;
	return (time_currently);
}
