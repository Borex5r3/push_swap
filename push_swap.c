/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:20 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 10:00:07 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_fill_stack_b(t_list **head_a, t_list **head_b, int size, int i)
{
	int		j;
	t_list	*tmp;
	int		num;

	j = 0;
	while (j < size)
	{
		tmp = *head_a;
		num = tmp->index;
		if (((num >> i) & 1) == 1)
			ra(head_a);
		else
			pb(head_a, head_b);
		j++;
	}
}

void	radix_sort(t_list **head_a, t_list **head_b, int size)
{
	int		i;
	int		max;
	int		max_bits;

	max = size - 1;
	max_bits = 0;
	i = 0;
	while ((max >> max_bits))
			max_bits++;
	while (i < max_bits)
	{
		radix_fill_stack_b(head_a, head_b, size, i);
		while (*head_b)
			pa(head_a, head_b);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;
	int		size;

	head_a = NULL;
	head_b = NULL;
	if (ac >= 2)
	{
		split_and_create_lst(&head_a, av, ac);
		size = lst_size(head_a);
		check_duplicate(&head_a);
		if (is_sorted(&head_a))
			return (0);
		small_sort(&head_a, &head_b, size);
		fill_index(&head_a);
		radix_sort(&head_a, &head_b, size);
	}
	return (0);
}
