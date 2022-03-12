/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:20 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/12 08:00:40 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **p)
{
	free(*p);
	*p = NULL;
}

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

void	sort_three(t_list **head_a)
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
	else if ((tmp->content > tmp->next->next->content) && (tmp->next->content < tmp->next->next->content))
		ra(head_a);
	else if ((tmp->next->content > tmp->next->next->content) && (tmp->content < tmp->next->next->content))
	{	
		sa(head_a);
		ra(head_a);
	}
	else if (tmp->content > tmp->next->next->content && tmp->content < tmp->next->content)
		rra(head_a);
}

int	small_num(t_list **head_a)
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

size_t	lst_size(t_list *head_a)
{
	size_t	size;

	size = 0;
	while (head_a)
	{
		size++;
		head_a = head_a->next;
	}
	return (size);
}

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	*sort_list(t_list *head_a, size_t size)
{
	int		*array;
	size_t	i;
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
	{
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
	}
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
	size_t	size;
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

void	sort_four(t_list **head_a, t_list **head_b)
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

void	sort_five(t_list **head_a, t_list **head_b)
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

int	main(int ac, char **av)
{
	int		i;
	t_list	*head_a;
	t_list	*head_b;
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*new;
	int		size;
	int		max;
	int		max_bits;
	int		num_check;
	int		j;
	int		num;

	i = ac - 1;
	size = i;
	max = size - 1;
	max_bits = 0;
	head_a = NULL;
	head_b = NULL;
	if (ac > 2)
	{
		while (i > 0)
		{
			if (!head_a)
				head_a = ft_lstnew(ft_atoi(av[i]));
			else
			{
				new = ft_lstnew(ft_atoi(av[i]));
				ft_lstadd_front(&head_a, new);
			}
			i--;
		}
		tmp = head_a;
		while (tmp->next)
		{
			num_check = tmp->content;
			tmp1 = tmp->next;
			while (tmp1)
			{
				if (tmp1->content == num_check)
				{
					printf("Error\n");
					exit(1);
				}
				tmp1 = tmp1->next;
			}
			tmp = tmp->next;
		}
		if (is_sorted(&head_a))
			return (0);
		tmp = head_a;
		if (ac == 3)
		{
			ra(&head_a);
			return (0);
		}
		else if (ac == 4)
		{
			sort_three(&head_a);
			return (0);
		}
		else if (ac == 5)
		{
			sort_four(&head_a, &head_b);
			return (0);
		}
		else if (ac == 6)
		{
			sort_five(&head_a, &head_b);
			return (0);
		}
		i = 0;
		tmp = head_a;
		while (tmp)
		{
			tmp->index = 0;
			tmp = tmp->next;
		}
		fill_index(&head_a);
		while ((max >> max_bits))
			max_bits++;
		while (i < max_bits)
		{
			j = 0;
			while (j < size)
			{
				tmp = head_a;
				num = tmp->index;
				if (((num >> i) & 1) == 1)
					ra(&head_a);
				else
					pb(&head_a, &head_b);
				j++;
			}
			while (head_b)
				pa(&head_a, &head_b);
			i++;
		}
		free (new);
	}
	return (0);
}
