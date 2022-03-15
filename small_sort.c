/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:36:23 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 09:45:26 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **head_a)
{
	t_list	*tmp;

	tmp = *head_a;
	if ((tmp->content > tmp->next->content)
		&& (tmp->content < tmp->next->next->content))
		sa(head_a);
	else if ((tmp->content > tmp->next->content)
		&& (tmp->next->content > tmp->next->next->content))
	{
		sa(head_a);
		rra(head_a);
	}
	else if ((tmp->content > tmp->next->next->content)
		&& (tmp->next->content < tmp->next->next->content))
		ra(head_a);
	else if ((tmp->next->content > tmp->next->next->content)
		&& (tmp->content < tmp->next->next->content))
	{	
		sa(head_a);
		ra(head_a);
	}
	else if (tmp->content > tmp->next->next->content
		&& tmp->content < tmp->next->content)
		rra(head_a);
}

static int	small_num(t_list **head_a)
{
	int		i;
	t_list	*tmp;
	int		num;

	tmp = *head_a;
	num = tmp->content;
	i = 0;
	while (tmp)
	{
		if (num > tmp->content)
			num = tmp->content;
		tmp = tmp->next;
	}
	tmp = *head_a;
	while (tmp)
	{
		if (num == tmp->content)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	sort_four(t_list **head_a, t_list **head_b)
{
	int	i;

	i = small_num(head_a);
	if (i >= 2)
	{
		if (i == 2)
		{
			rra(head_a);
			rra(head_a);
		}
		else if (i == 3)
			rra(head_a);
	}
	else if (i == 1)
		ra(head_a);
	pb(head_a, head_b);
	sort_three(head_a);
	pa(head_a, head_b);
}

static void	sort_five(t_list **head_a, t_list **head_b)
{
	int	i;

	i = small_num(head_a);
	if (i <= 2)
	{
		while (i != 0)
		{
			ra(head_a);
			i--;
		}
	}
	else if (i > 2)
	{
		while (i != 5)
		{
			rra(head_a);
			i++;
		}
	}
	pb(head_a, head_b);
	sort_four(head_a, head_b);
	pa(head_a, head_b);
}

void	small_sort(t_list **head_a, t_list **head_b, int size)
{
	if (size == 2)
	{
		ra(head_a);
		exit(0);
	}
	else if (size == 3)
	{
		sort_three(head_a);
		exit(0);
	}
	else if (size == 4)
	{
		sort_four(head_a, head_b);
		exit(0);
	}
	else if (size == 5)
	{
		sort_five(head_a, head_b);
		exit(0);
	}
}
