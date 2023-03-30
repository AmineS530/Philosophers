/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:58 by asadik            #+#    #+#             */
/*   Updated: 2023/03/30 18:00:28 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# define RED "\e[31m"
# define YELLOW "\e[33m"
# define GREEN "\e[32m"
# define CYAN "\e[36m"
# define DEFAULT "\033[0m"
# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	int	i;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}		t_data;

typedef struct s_philosopher
{
	int	position;
	int	is_dead;
}		t_philosopher;

int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		better_ft_isdigit(char *nbr);
int		ft_isdigit(int c);

int		handle_args(t_data *info,int argc, char *argv[]);

#endif
