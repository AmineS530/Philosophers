
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:35 by asadik            #+#    #+#             */
/*   Updated: 2023/05/11 16:31:51 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_actions(void *doingit)
{
	t_data	*doing;
	int		forks[2];

	doing = (t_data *)doingit;
	while (!doing->info->finished)
	{
		forks[0] = doing->position;
		forks[1] = doing->next->position;
		if (doing->info->number_of_philosophers == 1)
		{
			ft_usleep(1000);
			break;
		}
		pick_forks(doing, forks);
		eat(doing);
		put_down_forks(doing, forks);
		ft_print("is sleeping", doing);
		ft_usleep(doing->info->time_to_sleep);
		ft_print("is thinking", doing);
		usleep(200);
	}
	return (NULL);
}

void	pick_forks(t_data *philo, int *n_fork)
{
	pthread_mutex_lock(&philo->info->fork_n[n_fork[0]]);
	ft_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->info->fork_n[n_fork[1]]);
	ft_print("has taken a fork", philo);
}

void	eat(t_data *philo)
{
	if (!philo->info->finished)
	{
		ft_print("is eating", philo);
		ft_usleep(philo->info->time_to_eat);
		philo->last_time_ate = ft_time();
		philo->has_eaten++;
		if (philo->info->number_of_times_each_philosopher_must_eat != -1)
		{
			if (philo->has_eaten
				>= philo->info->number_of_times_each_philosopher_must_eat)
				philo->info->all_did_eat++;
		}
		if (philo->info->number_of_times_each_philosopher_must_eat != -1)
		{
			if (philo->info->all_did_eat == philo->info->number_of_times_each_philosopher_must_eat)
				philo->info->finished = TRUE;
		}
	}
}

void	put_down_forks(t_data *philo, int *fork)
{
		pthread_mutex_unlock(&philo->info->fork_n[fork[0]]);
		pthread_mutex_unlock(&philo->info->fork_n[fork[1]]);
}

void	*check_if_dead(void *dead)
{
	t_data *ded;

	ded = dead;
	while (!ded->info->finished)
	{
		if (!ded->info->finished && ft_time() - ded->last_time_ate > ded->info->time_to_die)
		{
			printf("%ld %d %s\n", time_stamp(ded),
			ded->position + 1, RED"died"DEFAULT);
			ded->info->finished = TRUE;
		}
		usleep(200);
	}
	return (NULL);
}
