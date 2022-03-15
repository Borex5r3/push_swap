/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:48:53 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 09:56:11 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	sort_array(int *array, int size)
{
	int	is_sorted;
	int	i;

	is_sorted = 1;
	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			swap(array + i, array + i + 1);
			is_sorted = 0;
		}
		i++;
	}
	return (is_sorted);
}

int	*sort_list(t_list *head_a, int size)
{
	int		*array;
	int		i;
	char	is_sorted;

	i = 0;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (head_a)
	{
		array[i] = head_a->content;
		head_a = head_a->next;
		i++;
	}
	is_sorted = 0;
	while (!is_sorted)
		is_sorted = sort_array(array, size);
	return (array);
}

int	find_index(int *array, int content)
{
	int	i;

	i = 0;
	while (array[i] != content)
		i++;
	return (i);
}

void	fill_index(t_list **head_a)
{
	t_list	*tmp;
	int		size;
	int		*array;

	size = lst_size(*head_a);
	array = sort_list(*head_a, size);
	tmp = *head_a;
	while (tmp)
	{
		tmp->index = find_index(array, tmp->content);
		tmp = tmp->next;
	}
	free(array);
}
