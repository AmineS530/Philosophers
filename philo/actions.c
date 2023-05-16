/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:35 by asadik            #+#    #+#             */
/*   Updated: 2023/05/16 21:09:51 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_actions(void *doingit)
{
	t_data	*doing;
	int		forks[2];

	doing = (t_data *)doingit;
	if ((doing->position % 2) == 0)
		usleep(200);
	while (1)
	{
		forks[0] = doing->position;
		forks[1] = doing->next->position;
		pick_fork(doing, forks[0]);
		if (doing->info->number_of_philosophers == 1)
		{
			ft_usleep(1000);
			break ;
		}
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
	pthread_mutex_lock(&philo->eating);
	philo->last_time_ate = ft_time();
	pthread_mutex_unlock(&philo->eating);
	philo->times_eaten++;
}

void	put_down_forks(t_data *philo, int fork1, int fork2)
{
	pthread_mutex_unlock(&philo->info->fork_n[fork1]);
	pthread_mutex_unlock(&philo->info->fork_n[fork2]);
}

void	check_if_dead(t_data *dead)
{
	dead->info->i = 0;


	while (1)
	{
		usleep(100);
		pthread_mutex_lock(&dead->eating);
		if ((ft_time()
				- dead->info->philos->last_time_ate) > dead->info->time_to_die)
		{
			ft_print(RED "died" DEFAULT, dead->info->philos);
			dead->info->finished = TRUE;
			pthread_mutex_lock(&dead->info->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&dead->eating);
		if (dead->info->number_of_times_each_philosopher_must_eat != -1)
		{
			if (dead->info->philos->times_eaten == dead->info->number_of_times_each_philosopher_must_eat)
				dead->info->all_did_eat++;
			if (dead->info->all_did_eat >= dead->info->number_of_times_each_philosopher_must_eat)
			{
				dead->info->finished = TRUE;
				pthread_mutex_lock(&dead->info->print_mutex);
				break ;
			}
		}
		dead->info->philos = dead->info->philos->next;
	}
}
