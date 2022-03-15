/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_indexed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:55:32 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 09:55:59 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_indexed(t_list **head_a)
{
	t_list	*tmp;
	int		a;

	tmp = *head_a;
	a = 0;
	if (!tmp->next)
		return (0);
	while (tmp)
	{
		if (tmp->index == 0 && a == 0)
			a++;
		else if (tmp->index == 0 && a != 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
