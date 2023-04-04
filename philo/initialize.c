/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:31:00 by asadik            #+#    #+#             */
/*   Updated: 2023/04/04 17:57:21 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init(t_data *thing)
{
	thing->info->thread = malloc(sizeof(pthread_t)
			* (thing->info->number_of_philosophers));
	thing->info->fork_n = malloc(sizeof(pthread_mutex_t)
			* (thing->info->number_of_philosophers));
	if (!thing->info->thread)
		return (1);
	thing = init_philos(thing);
	if (create_join(thing) == 1)
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
		ft_lstadd_back(&philosophers, new);
	}
	philosophers = ft_loop_lst(philosophers);
	return (philosophers);
}

int	create_join(t_data *thing)
{
	thing->info->i = 0;
	while (thing->info->i < thing->info->number_of_philosophers)
	{
		if (pthread_create(&thing->info->thread[thing->info->i++],
				NULL, check_if_dead, thing) != 0)
			return (1);
		usleep(69);
		thing = thing->next;
	}
	thing->info->i = 0;
	while (thing->info->i < thing->info->number_of_philosophers)
	{
		if (pthread_join(thing->info->thread[thing->info->i++], NULL) != 0)
			return (1);
	}
	return (0);
}
