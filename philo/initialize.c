/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:31:00 by asadik            #+#    #+#             */
/*   Updated: 2023/04/02 18:51:58 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *info)
{
	t_data	*philosophers;
	t_data	*new;

	info->thread = malloc(sizeof(pthread_t)
			* (info->number_of_philosophers + 1));
	if (!info->thread)
		return (1);
	info->i = 0;
	philosophers = NULL;
	while (info->i < info->number_of_philosophers)
	{
		new = ft_lstnew(info->i);
		ft_lstadd_back(&philosophers, new);
		if (pthread_create(&info->thread[info->i++],
				NULL, check_if_dead, &philosophers) != 0)
			return (1);
		usleep(69);
	}
	philosophers = ft_loop_lst(philosophers);
	return (0);
}

void	*check_if_dead(void *ded)
{
	t_data	*test;

	test = ded;
	printf("お前はもう死んでる at %lld %lld\n", ft_time(), time_stamp(test));
	sleep (1);
	if (!test->skip && test->is_dead)
		test->skip = TRUE;
	return (NULL);
}
