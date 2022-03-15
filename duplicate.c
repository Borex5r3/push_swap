/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:14:16 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 08:00:14 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "push_swap.h"

void	check_duplicate(t_list **head_a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		num_check;

	tmp = *head_a;
	while (tmp->next)
	{
		num_check = tmp->content;
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp1->content == num_check)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
