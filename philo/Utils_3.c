/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:48:05 by asadik            #+#    #+#             */
/*   Updated: 2023/04/02 18:10:15 by asadik           ###   ########.fr       */
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
