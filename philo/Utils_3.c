/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:48:05 by asadik            #+#    #+#             */
/*   Updated: 2023/05/04 17:15:37 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*ft_loop_lst(t_data *lst)
{
	t_data	*head;

	head = lst;
	while (lst && lst->next != NULL)
		lst = lst->next;
	lst->next = head;
	return (head);
}

void	ft_print(char *str, t_data *philosopher)
{
	pthread_mutex_lock(&philosopher->info->print_mutex);
	printf("%ld %d %s\n", time_stamp(philosopher),
		philosopher->position + 1, str);
	pthread_mutex_unlock(&philosopher->info->print_mutex);
}

void	ft_usleep(int time)
{
	usleep(time * 1000);
}
