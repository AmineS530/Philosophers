/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:35 by asadik            #+#    #+#             */
/*   Updated: 2023/05/18 11:20:26 by asadik           ###   ########.fr       */
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
		pick_fork(doing, forks[1]);
		eat(doing);
		pthread_mutex_unlock(&doing->info->fork_n[forks[0]]);
		pthread_mutex_unlock(&doing->info->fork_n[forks[1]]);
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
	pthread_mutex_lock(&philo->last_time_ate_mutex);
	philo->last_time_ate = ft_time();
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->last_time_ate_mutex);
}

int	check_eat_times(t_data *food)
{
	if (food->info->number_of_times_each_philosopher_must_eat != -1)
	{
		if (food->times_eaten
			== food->info->number_of_times_each_philosopher_must_eat)
			food->info->all_did_eat++;
		if (food->info->all_did_eat
			>= food->info->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_lock(&food->info->print_mutex);
			return (1);
		}
		pthread_mutex_unlock(&food->last_time_ate_mutex);
	}
	return (0);
}

void	check_if_dead(t_data *dead)
{
	dead->info->i = 0;
	while (1)
	{
		pthread_mutex_lock(&dead->last_time_ate_mutex);
		if ((ft_time()
				- dead->last_time_ate) > dead->info->time_to_die)
		{
			pthread_mutex_unlock(&dead->last_time_ate_mutex);
			ft_print(RED "died" DEFAULT, dead->info->philos);
			pthread_mutex_lock(&dead->info->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&dead->last_time_ate_mutex);
		pthread_mutex_lock(&dead->last_time_ate_mutex);
		if (check_eat_times(dead) == 1)
			break ;
		pthread_mutex_unlock(&dead->last_time_ate_mutex);
		dead->info->philos = dead->info->philos->next;
		usleep(200);
	}
}
