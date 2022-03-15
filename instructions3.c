/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:26:20 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/14 10:27:01 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "push_swap.h"

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*tmp0;

	tmp0 = *head_b;
	if (!tmp0)
		return ;
	*head_b = tmp0->next;
	if (!*head_a)
	{
		tmp0->next = NULL;
		*head_a = tmp0;
	}
	else
	{
		tmp0->next = *head_a;
		*head_a = tmp0;
	}
	write(1, "pa\n", 3);
}
