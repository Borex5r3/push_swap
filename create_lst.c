/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:21:27 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 09:56:20 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "push_swap.h"

static void	fill_lst(t_list **head_a, char **splt, int j)
{
	t_list	*new;

	while (j >= 0)
	{
		if (!*head_a)
			*head_a = ft_lstnew(ft_atoi(splt[j]));
		else
		{
			new = ft_lstnew(ft_atoi(splt[j]));
			ft_lstadd_front(head_a, new);
		}
		j--;
	}
}

void	split_and_create_lst(t_list **head_a, char **av, int ac)
{
	char	**splt;
	int		j;
	int		i;

	i = ac - 1;
	while (i > 0)
	{	
		splt = ft_split(av[i], ' ');
		j = 0;
		while (splt[j])
			j++;
		j--;
		fill_lst(head_a, splt, j);
		i--;
	}
}
