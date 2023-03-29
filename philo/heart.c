/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:22 by asadik            #+#    #+#             */
/*   Updated: 2023/03/29 18:42:33 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* number_of_philosophers time_to_die time_to_eat
//* time_to_sleep [number_of_times_each_philosopher_must_eat]


void	handle_args(t_data *info, char *argv[])
{
	info->i = 0;
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

void	*test_action(void)
{
	return (0);
}

int	main(int argc, char *argv[])
{
	int			number_of_philosophers;
	pthread_t	*philos;
	int			i;
	t_data		all;
	void* (*ptr)(void *) = (void* (*)(void *))main;

	if (argc == 6)
	{
		handle_args(&all, argv);
		i = 0;
		write(1, "Yes.", 4);
		number_of_philosophers = ft_atoi(argv[1]);
		philos = malloc(sizeof(pthread_t) * (number_of_philosophers + 1));
		while (i < 6)
			pthread_create(&philos[i++], NULL, ptr, NULL);
		sleep(1);
		printf("ayaya \n");
		i = 0;
		while (i < 6)
			pthread_join(philos[i++], NULL);
	}
	return (0);
}
