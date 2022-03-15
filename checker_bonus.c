/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:16:11 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 09:56:35 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int main(int ac, char **av)
{
    t_list  *head_a;
	t_list  *head_b;
    t_list  *tmp;

	head_a = NULL;
	head_b = NULL;
    if (ac > 1)
    {
        split_and_create_lst(&head_a, av, ac);
        tmp = head_a;
        while (tmp)
        {
            printf("| %d |\n", tmp->content);
            tmp = tmp->next;
        }
        check_duplicate(&head_a);
    }
}
