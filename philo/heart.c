/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:22 by asadik            #+#    #+#             */
/*   Updated: 2023/05/14 20:11:02 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* number_of_philosophers time_to_die time_to_eat
//* time_to_sleep [number_of_times_each_philosopher_must_eat]

void	check(void)
{
	system("leaks philosophers");
}

void	ft_free(t_data *all)
{
	free (all->info->fork_n);
	ft_lstclear(&all->info->philos);
}

	//atexit(check);
int	main(int argc, char *argv[])
{
	t_data		all;
	t_basics	stuff;

	if (argc == 5 || argc == 6)
	{
		if (handle_args(&stuff, argc, argv) == 1)
			return (1);
		if (check_info(&stuff) == 1)
			return (1);
		all.info = &stuff;
		all.info->finished = FALSE;
		if (init(&all) == 1)
			return (1);
	//	ft_free(&all);
	}
	else
		ft_print_error(RED"Usage: ./philosophers number_of_philosophers"
			" time_to_die time_to_eat time_to_sleep"
			" [number_of_times_each_philosopher_must_eat]"DEFAULT);

	while (1)
	{
		all.info->i = 0;
		while (all.info->i < all.info->number_of_philosophers)
		{
			if ((ft_time() - all.info->philos->last_time_ate) > all.info->time_to_die)
			{
			ft_print(RED"died"DEFAULT,all.info->philos);
			all.info->finished = TRUE;
			pthread_mutex_lock(&all.info->print_mutex);
			return (69);
			}
			if (all.info->number_of_times_each_philosopher_must_eat != -1)
			{
				if (all.info->philos->times_eaten
					== all.info->number_of_times_each_philosopher_must_eat)
						all.info->all_did_eat++;
				if (all.info->all_did_eat
					>= all.info->number_of_times_each_philosopher_must_eat)
				{
					all.info->finished = TRUE;
					pthread_mutex_lock(&all.info->print_mutex);
					return (69);
				}
			}
			all.info->philos = all.info->philos->next;
		}
	}
	return (0);
}

	// void* (*ptr)(void *) = (void* (*)(void *))main;
		// all.i = 0;
		// while (all.i < all.number_of_philosophers)
		// 	pthread_create(&philos[all.i++], NULL, ptr, NULL);
		// all.i = 0;
		// printf("ayaya \n");
		// while (all.i < all.number_of_philosophers)
		// 	pthread_join(philos[all.i++], NULL);
		// free(philos);
