/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:35 by asadik            #+#    #+#             */
/*   Updated: 2023/04/16 19:38:41 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_actions(void *doingit)
{
	t_data	*doing;
	int		forks[2];

	doing = doingit;
	while (!doing->info->finished)
	{
		if (doing->info->all_did_eat >= doing->info->number_of_times_each_philosopher_must_eat)
			break;
		forks[0] = doing->position;
		forks[1] = doing->next->position;
		pick_fork(doing, forks[0]);
		pick_fork(doing, forks[1]);
		eat(doing);
		put_down_forks(doing, forks[0], forks[1]);
		sleeping_and_thinking(doing);
	}
	return (NULL);
}

void	pick_fork(t_data *philo, int n_fork)
{
	pthread_mutex_lock(&philo->info->fork_n[n_fork]);
	ft_print("has taken a fork", philo);
}

void	eat(t_data *philo)
{
	ft_print("is eating", philo);
	usleep(philo->info->time_to_eat * 1000);
	philo->last_time_ate = ft_time();
	philo->has_eaten++;
	if (philo->info->number_of_times_each_philosopher_must_eat >= 1)
	{
		if (philo->has_eaten
			== philo->info->number_of_times_each_philosopher_must_eat)
			philo->info->all_did_eat++;
	}
}

void	put_down_forks(t_data *philo, int frst_fork, int scnd_fork)
{
	pthread_mutex_unlock(&philo->info->fork_n[frst_fork]);
	pthread_mutex_unlock(&philo->info->fork_n[scnd_fork]);
}

void	sleeping_and_thinking(t_data *philo)
{
	ft_print("is sleeping", philo);
	usleep(philo->info->time_to_sleep * 1000);
	ft_print("is thinking", philo);
}
void	*check_if_dead(void *ded)
{
	// t_data	*test;

	// test = (t_data *)ded;
	// if (ded->is_dead)
	// {
		ft_print("お前はもう死んでる\n", ded);
	// }
	// if (!test->info->finished && test->is_dead)
	// 	test->info->finished = TRUE;
	return (NULL);
}
