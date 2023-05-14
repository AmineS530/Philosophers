/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:31:00 by asadik            #+#    #+#             */
/*   Updated: 2023/05/14 20:12:16 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_data *thing)
{
	thing->info->fork_n = malloc(sizeof(pthread_mutex_t)
			* (thing->info->number_of_philosophers));
	if (!thing->info->fork_n)
		return (1);
	thing->info->philos = init_philos(thing);
	thing->info->all_did_eat = 0;
	init_mutex(thing);
	if (create_join(thing->info->philos) == 1)
		return (1);
	return (0);
}

t_data	*init_philos(t_data *thing)
{
	t_data	*philosophers;
	t_data	*new;

	thing->info->i = 0;
	philosophers = NULL;
	while (thing->info->i < thing->info->number_of_philosophers)
	{
		new = ft_lstnew(thing->info->i++);
		new->info = thing->info;
		if (thing->info->i == thing->info->number_of_philosophers)
			new->end_tail = TRUE;
		ft_lstadd_back(&philosophers, new);
	}
	philosophers = ft_loop_lst(philosophers);
	return (philosophers);
}

void	init_mutex(t_data *thing)
{
	int	i;

	i = 0;
	pthread_mutex_init(&thing->info->print_mutex, NULL);
	pthread_mutex_init(&thing->info->eating, NULL);
	while (i < thing->info->number_of_philosophers)
		pthread_mutex_init(&thing->info->fork_n[i++], NULL);
}

int	create_join(t_data *thing)
{
	thing->info->i = 1;
	while (thing->info->i <= thing->info->number_of_philosophers)
	{
		if (pthread_create(&thing->info->philos->thread,
				NULL, do_actions, thing->info->philos) != 0)
			return (1);
		usleep(200);
		thing->info->philos = thing->info->philos->next;
		thing->info->i++;
	}
	return (0);
}
