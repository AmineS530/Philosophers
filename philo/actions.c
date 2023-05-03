/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:35 by asadik            #+#    #+#             */
/*   Updated: 2023/05/01 18:47:25 by asadik           ###   ########.fr       */
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

			if (doing->info->number_of_times_each_philosopher_must_eat != -1)
		{
			if (doing->info->all_did_eat >= doing->info->number_of_times_each_philosopher_must_eat)
			{
				doing->info->finished = 1;
			}
		}
		forks[0] = doing->position;
		forks[1] = doing->next->position;
		pick_fork(doing, forks[0]);
		pick_fork(doing, forks[1]);
		eat(doing);
		put_down_forks(doing, forks[0], forks[1]);
		ft_print("is sleeping", doing);
		ft_usleep(doing->info->time_to_sleep);
		ft_print("is thinking", doing);
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
	ft_usleep(philo->info->time_to_eat);
	philo->last_time_ate = ft_time();
	philo->has_eaten++;
	if (philo->info->number_of_times_each_philosopher_must_eat != -1)
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

void	check_if_dead(t_data *ded)
{
	if (ded->info->finished)
	{
		ft_print("お前はもう死んでる\n", ded);
	}
	if (ft_time() - ded->last_time_ate > ded->info->time_to_die)
		ded->info->finished = TRUE;

}
