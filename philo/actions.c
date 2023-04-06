/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:09:35 by asadik            #+#    #+#             */
/*   Updated: 2023/04/05 01:08:56 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_if_dead(void *ded)
{
	t_data	*test;

	test = (t_data *)ded;
	if (test->is_dead)
	{
		printf("お前はもう死んでる at %ld\n", time_stamp(test));
	}
	if (!test->info->finished && test->is_dead)
		test->info->finished = TRUE;
	return (NULL);
}
