/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:58:57 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/27 11:18:39 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*give_cheapest(t_pile *pile)
{
	if (pile == NULL)
		return (NULL);
	while (pile)
	{
		if (pile->cheapest)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}

bool	is_sorted(t_pile *pile)
{
	if (pile == NULL)
		return (1);
	while (pile->next)
	{
		if (pile->value > pile->next->value)
			return (false);
		pile = pile->next;
	}
	return (true);
}

void	mini_algo(t_pile **pile)
{
	t_pile	*highest_node;

	if ((is_sorted(*pile)))
		return ;
	highest_node = find_highest(*pile);
	if (*pile == highest_node)
		make_ra(pile);
	else if ((*pile)->next == highest_node)
		make_rra(pile);
	if ((*pile)->value > (*pile)->next->value)
		make_sa(pile);
}

void	sort_five(t_pile **pile_a, t_pile **pile_b)
{
	while (ft_lstsize(*pile_a) > 3)
	{
		init_nodes(*pile_a, *pile_b);
		final_rotations(pile_a, find_small(*pile_a), 'a');
		make_pb(pile_a, pile_b);
	}
}
