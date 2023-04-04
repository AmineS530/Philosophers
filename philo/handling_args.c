/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:17:02 by asadik            #+#    #+#             */
/*   Updated: 2023/04/03 16:44:00 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_args(t_basics *info, int argc, char *argv[])
{
	info->i = 1;
	while (argv[info->i])
	{
		if (!better_ft_isdigit(argv[info->i]))
			return(ft_print_error(RED"Error\nInvalid arguments"DEFAULT));
		info->i++;
	}
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (info->number_of_times_each_philosopher_must_eat < 0)
			return(ft_print_error(RED"Erro\nInvalid Optional argument"DEFAULT));
	}
	return (0);
}

int	check_info(t_basics *info)
{
	if (info->number_of_philosophers <= 0)
		return(ft_print_error(RED"Error\nInvalid number of philosophers"DEFAULT));
	if (info->time_to_die < 0)
		return(ft_print_error(RED"Error\nInvalid Death timer"DEFAULT));
	if (info->time_to_eat < 0)
		return(ft_print_error(RED"Error\nInvalid time_to_eat"DEFAULT));
	if (info->time_to_sleep < 0)
		return(ft_print_error(RED"Error\nInvalid Sleep timer"DEFAULT));
	return (0);
}
