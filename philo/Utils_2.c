/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:57:59 by asadik            #+#    #+#             */
/*   Updated: 2023/05/11 16:31:32 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*ft_lstnew(int pos)
{
	t_data	*poggers;

	poggers = malloc(sizeof(t_data));
	if (!poggers)
		return (NULL);
	poggers->position = pos;
	if (pos == 0)
		poggers->real_head = TRUE;
	else
		poggers->real_head = FALSE;
	poggers->end_tail = FALSE;
	poggers->philo_creation_time = ft_time();
	poggers->last_time_ate = poggers->philo_creation_time;
	poggers->has_eaten = 0;
	poggers->next = NULL;
	return (poggers);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*tmp;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	ft_lstclear(t_data **lst)
{
	t_data	*tmp;

	if (!lst)
		return ;
	tmp = (*lst);
	while (tmp->end_tail != TRUE)
	{
		tmp = (*lst)->next;
		free (*lst);
		*lst = tmp;
	}
	free (*lst);
	return ;
}

long	ft_time(void)
{
	long			ayaya;
	struct timeval	ze_time;

	gettimeofday(&ze_time, NULL);
	ayaya = ((ze_time.tv_sec * 1000) + (ze_time.tv_usec / 1000));
	return (ayaya);
}

long	time_stamp(t_data *the_time)
{
	return (ft_time() - the_time->philo_creation_time);
}
