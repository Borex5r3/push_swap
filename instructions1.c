/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:19:58 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/14 10:24:29 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "push_swap.h"

void	sa(t_list **head_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_a;
	if (!tmp1->next)
		return ;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*head_a = tmp2;
	write(1, "sa\n", 3);
}

void	sb(t_list **head_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_b;
	if (!tmp1->next)
		return ;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*head_b = tmp2;
	write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
	write(1, "ss\n", 3);
}

void	ra(t_list **head_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_a;
	if (!tmp1 || !tmp1->next)
		return ;
	tmp2 = *head_a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	*head_a = tmp1->next;
	tmp1->next = NULL;
	tmp2->next = tmp1;
	write(1, "ra\n", 3);
}

void	rb(t_list **head_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_b;
	if (!tmp1 || !tmp1->next)
		return ;
	tmp2 = *head_b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	*head_b = tmp1->next;
	tmp1->next = NULL;
	tmp2->next = tmp1;
	write(1, "rb\n", 3);
}
