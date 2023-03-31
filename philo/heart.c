/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:22 by asadik            #+#    #+#             */
/*   Updated: 2023/03/31 18:02:16 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* number_of_philosophers time_to_die time_to_eat
//* time_to_sleep [number_of_times_each_philosopher_must_eat]

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
		if (check_info(&all) == 1)
			return (1);
		philos = malloc(sizeof(pthread_t) * (all.number_of_philosophers + 1));
		if (!philos)
			return (1);
		all.i = 0;
		while (all.i < all.number_of_philosophers)
			pthread_create(&philos[all.i++], NULL, ptr, NULL);
		all.i = 0;
		printf("ayaya \n");
		while (all.i < all.number_of_philosophers)
			pthread_join(philos[all.i++], NULL);
		free(philos);
	}
	else
		ft_print_error(RED"Usage: ./philosophers number_of_philosophers time_to_die"
				" time_to_eat time_to_sleep"
				" [number_of_times_each_philosopher_must_eat]"DEFAULT);
	return (0);
}
