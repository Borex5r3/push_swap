/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:20 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/19 22:57:04 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*tmp;
	t_list	*new;

	i = 1;
	head = NULL;
	if (ac > 1)
	{
		while (av[i])
		{
			if (!head)
				head = ft_lstnew(ft_atoi(av[i]));
			else
			{
				new = ft_lstnew(ft_atoi(av[i]));
				ft_lstadd_back(&head, new);
			}
			i++;
		}
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
