/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:57:08 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/24 16:31:39 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_before_tail(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next && pile->next->next != NULL)
		pile = pile -> next;
	return (pile);
}

void    reverse_rotate(t_pile **pile)
{
    t_pile     *temp;
    t_pile     *tail;
    t_pile     *before_tail;

    tail = ft_lstlast(*pile);
    before_tail = get_before_tail(*pile);
    temp = *pile;
    *pile = tail;
    (*pile)->next = temp;
    before_tail->next = NULL;
}

void    make_rra(t_pile **pile_a)
{
    reverse_rotate(pile_a);
    ft_putstr_fd("rra\n", 1);
}

void    make_rrb(t_pile **pile_b)
{
    reverse_rotate(pile_b);
    ft_putstr_fd("rrb\n", 1);
}

void    make_rrr(t_pile **pile_a, t_pile **pile_b)
{
    reverse_rotate(pile_a);
    reverse_rotate(pile_b);
    ft_putstr_fd("rrr\n", 1);
}