/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:52:42 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 09:56:02 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "push_swap.h"

int	is_sorted(t_list **head_a)
{
	t_list	*tmp;

	tmp = *head_a;
	if (!tmp->next)
		return (0);
	while (tmp->next)
	{
		if (tmp->next)
			if (tmp->content > tmp->next->content)
				return (0);
		tmp = tmp->next;
	}
	return (1);
}
