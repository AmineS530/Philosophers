/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:09:12 by asadik            #+#    #+#             */
/*   Updated: 2023/04/01 17:13:53 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	while (*s)
		write (fd, s++, 1);
}

int	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

int	better_ft_isdigit(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i + 1] != '\0')
	{
		if (nbr[i] == '-' || nbr[i] == '+')
		{
			if (ft_isdigit(nbr[i + 1]))
				return (1);
			else
				return (ft_isdigit(nbr[i]));
		}
		i++;
	}
	return (ft_isdigit(nbr[i]));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
