/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:20 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/20 19:00:54 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **p)
{
	free(*p);
	*p = NULL;	
}

t_list	*sa(t_list *head)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp0;
	int		i;

	i = 0;
	tmp0 = head;
	tmp1 = head->next;
	tmp2 = tmp1->next;
	tmp0->next = tmp2;
	tmp1->next = tmp0;
	return (tmp1);
}

t_list	*ra(t_list *head)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp0;

	tmp0 = head;
	tmp1 = tmp0->next;
	tmp2 = tmp0;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp0;
	tmp0->next = NULL;
	return (tmp1);

}

t_list	*rra(t_list *head)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp0;

	tmp0 = head;
	tmp2 = head;
	while (tmp2->next)
	{
		if (!tmp2->next->next)
			tmp1 = tmp2;		
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp0;
	tmp1->next = NULL;
	return (tmp2);
}
int	main(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*tmp;
	t_list	*new;

	i = ac - 1;
	head = NULL;
	if (ac > 1)
	{
		while (i > 0)
		{
			if (!head)
				head = ft_lstnew(ft_atoi(av[i]));
			else
			{
				new = ft_lstnew(ft_atoi(av[i]));
				ft_lstadd_front(&head, new);
			}
			i--;
		}
		head = rra(head);
		tmp = head;
		while (tmp->next)
		{
			printf("%d -->", tmp->content);
			tmp = tmp->next;
		}
		printf("%d End of Node !!\n", tmp->content);
		free (new);
	}
	return (0);
}
