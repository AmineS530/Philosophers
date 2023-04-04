/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:58 by asadik            #+#    #+#             */
/*   Updated: 2023/04/04 17:58:39 by asadik           ###   ########.fr       */
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

typedef struct s_basics
{
	int					i;
	int					finished;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	pthread_t			*thread;
	pthread_mutex_t		*fork_n;
}				t_basics;
typedef struct s_data
{
	int					real_head;
	int					position;
	long				philo_creation_time;
	int					is_dead;
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

//*		handling_args
int			handle_args(t_basics *info, int argc, char *argv[]);
int			check_info(t_basics *info);

//* initialize
int			init(t_data *thing);
t_data		*init_philos(t_data *thing);
int			create_join(t_data *thing);

//* actions
void		*check_if_dead(void *ded);
#endif
