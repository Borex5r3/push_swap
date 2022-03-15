/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:50:16 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 09:56:06 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *head_a)
{
	int	size;

	size = 0;
	while (head_a)
	{
		size++;
		head_a = head_a->next;
	}
	return (size);
}
