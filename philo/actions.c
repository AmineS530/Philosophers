/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:35 by asadik            #+#    #+#             */
/*   Updated: 2023/05/11 18:34:38 by asadik           ###   ########.fr       */
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
		if ((doing->position % 2) == 0)
			usleep(200);
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
	if ((philo->position % 2) == 0)
		usleep (200);
	philo->last_time_ate = ft_time();
	philo->has_eaten++;
}

void	put_down_forks(t_data *philo, int fork1, int fork2)
{
	pthread_mutex_unlock(&philo->info->fork_n[fork1]);
	pthread_mutex_unlock(&philo->info->fork_n[fork2]);
}