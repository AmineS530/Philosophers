/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:09:12 by asadik            #+#    #+#             */
/*   Updated: 2023/03/29 18:19:00 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// atoi to convert the args
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	owo;

	sign = 1;
	owo = 0;
	result = 0;
	while ((str[owo] >= 9 && str[owo] <= 13) || str[owo] == ' ')
		owo++;
	while (str[owo] == '-' || str[owo] == '+')
	{
		if (str[owo + 1] == '-' || str[owo + 1] == '+')
			return (0);
		if (str[owo] == '-')
			sign *= -1;
		owo++;
	}
	while (str[owo] >= '0' && str[owo] <= '9')
	{
		result = result * 10;
		result += str[owo] - '0';
		owo++;
	}
	return (result * sign);
}

// putstr_fd to print texts and errors
void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	while (*s)
		write (fd, s++, 1);
}
