/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:22 by asadik            #+#    #+#             */
/*   Updated: 2023/03/30 18:04:53 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* number_of_philosophers time_to_die time_to_eat
//* time_to_sleep [number_of_times_each_philosopher_must_eat]

int	handle_args(t_data *info,int argc, char *argv[])
{
	info->i = 1;
	while (argv[info->i])
	{
		if (!better_ft_isdigit(argv[info->i]))
		{
			ft_putstr_fd(RED "Error\nInvalid Input" DEFAULT, 2);
			return (1);
		}
		info->i++;
	}
	info->number_of_philosophers = ft_atoi(argv[1]);
		printf("N of philosophers is %d\n", info->number_of_philosophers);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return (1);
}

void	check(void)
{
	system("leaks philosophers");
}

	// atexit(check);
int	main(int argc, char *argv[])
{
	t_data		all;
	pthread_t	*philos;
	void* (*ptr)(void *) = (void* (*)(void *))main;

	if (argc == 5 || argc == 6)
	{
		if (handle_args(&all, argc, argv) == 1)
			return (1);
		philos = malloc(sizeof(pthread_t) * (all.number_of_philosophers + 1));
		if (!philos)
			return (0);
		all.i = 0;
		while (all.i < all.number_of_philosophers)
			pthread_create(&philos[all.i++], NULL, ptr, NULL);
		all.i = 0;
		printf("ayaya \n");
		while (all.i < all.number_of_philosophers)
			pthread_join(philos[all.i++], NULL);
		free(philos);
	}
	return (0);
}
