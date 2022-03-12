/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:47:14 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/08 18:40:29 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check(size_t a, int s)
{
	if (a <= 2147483647)
		return (a * s);
	else if (a == 2147483648 && s == -1)
		return (-2147483648);
	else
	{
		printf("Error\n");
		exit(1);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	size_t	a;

	i = 0;
	s = 1;
	a = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - 48);
		i++;
	}
	if (str[i])
	{
		printf("Error\n");
		exit(1);
	}
	return (check(a, s));
}