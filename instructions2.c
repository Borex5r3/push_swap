/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:24:39 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/14 10:25:52 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "push_swap.h"

void	rr(t_list **head_a, t_list **head_b)
{
	ra(head_a);
	rb(head_b);
	write(1, "rr\n", 3);
}

void	rra(t_list **head_a)
{
	t_list	*tmp0;
	t_list	*tmp1;
	t_list	*tmp2;

	tmp0 = *head_a;
	if (!tmp0 || !tmp0->next)
		return ;
	tmp1 = *head_a;
	while (tmp0->next)
	{
		if (!tmp0->next->next)
			tmp2 = tmp0;
		tmp0 = tmp0->next;
	}
	tmp2->next = NULL;
	tmp0->next = tmp1;
	*head_a = tmp0;
	write(1, "rra\n", 4);
}

void	rrb(t_list **head_b)
{
	t_list	*tmp0;
	t_list	*tmp1;
	t_list	*tmp2;

	tmp0 = *head_b;
	if (!tmp0 || !tmp0->next)
		return ;
	tmp1 = *head_b;
	while (tmp0->next)
	{
		if (!tmp0->next->next)
			tmp2 = tmp0;
		tmp0 = tmp0->next;
	}
	tmp2->next = NULL;
	tmp0->next = tmp1;
	*head_b = tmp0;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	rra(head_a);
	rrb(head_b);
	write(1, "rrr\n", 4);
}

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp0;

	tmp0 = *head_a;
	if (!tmp0)
		return ;
	*head_a = tmp0->next;
	if (!*head_b)
	{
		tmp0->next = NULL;
		*head_b = tmp0;
	}
	else
	{
		tmp0->next = *head_b;
		*head_b = tmp0;
	}
	write(1, "pb\n", 3);
}
