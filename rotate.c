/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:51:49 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/27 11:29:09 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*tail;

	temp = *pile;
	*pile = (*pile)->next;
	tail = ft_lstlast(*pile);
	temp->next = NULL;
	tail->next = temp;
}

void	make_ra(t_pile **pile_a)
{
	rotate(pile_a);
	ft_putstr_fd("ra\n", 1);
}

void	make_rb(t_pile **pile_b)
{
	rotate(pile_b);
	ft_putstr_fd("rb\n", 1);
}

void	make_rr(t_pile **pile_a, t_pile **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	ft_putstr_fd("rr\n", 1);
}
