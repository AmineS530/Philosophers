/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:58 by asadik            #+#    #+#             */
/*   Updated: 2023/05/01 18:09:48 by asadik           ###   ########.fr       */
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

typedef struct s_data	t_data;
typedef struct s_basics
{
	int					i;
	int					finished;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	int					all_did_eat;
	t_data				*philos;
	pthread_t			*thread;
	pthread_mutex_t		*fork_n;
	pthread_mutex_t		print_mutex;
}				t_basics;
typedef struct s_data
{
	int					real_head;
	int					end_tail;
	int					position;
	long				philo_creation_time;
	long				last_time_ate;
	int					has_eaten;
	t_basics			*info;
	struct s_data		*next;
}				t_data;

//*		Utils
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_print_error(char *str);
int			better_ft_isdigit(char *nbr);
int			ft_isdigit(int c);

//*		Utils_2
t_data		*ft_lstnew(int pos);
void		ft_lstadd_back(t_data **lst, t_data *new);
void		ft_lstclear(t_data **lst);
long		ft_time(void);
long		time_stamp(t_data *the_time);

//*		Utils_3
t_data		*ft_loop_lst(t_data *lst);
void		ft_print(char *str, t_data *philosopher);
void		ft_usleep(int time);

//*		handling_args
int			handle_args(t_basics *info, int argc, char *argv[]);
int			check_info(t_basics *info);

//* initialize
int			init(t_data *thing);
t_data		*init_philos(t_data *thing);
void		init_mutex(t_data *thing);

int			create_join(t_data *thing);

//* actions
void		*do_actions(void *doingit);
void		pick_fork(t_data *philo, int n_fork);
void		eat(t_data *philo);
void		put_down_forks(t_data *philo, int frst_fork, int scnd_fork);

void		*check_if_dead(void *ded);

void		ft_free(t_data *all);

#endif
