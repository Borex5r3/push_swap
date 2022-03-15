/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:35 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/15 09:59:28 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}	t_list;
int		ft_atoi(const char *str);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
void	split_and_create_lst(t_list **head_a, char **av, int ac);
void	check_duplicate(t_list **head_a);
void	sa(t_list **head_a);
void	sb(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);
void	ra(t_list **head_a);
void	rb(t_list **head_b);
void	rr(t_list **head_a, t_list **head_b);
void	rra(t_list **head_a);
void	rrb(t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);
void	pa(t_list **head_a, t_list **head_b);
void	small_sort(t_list **head_a, t_list **head_b, int size);
int		lst_size(t_list *head_a);
int		is_sorted(t_list **head_a);
void	fill_index(t_list **head_a);

#endif