/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:53:11 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/27 11:24:12 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_pile **pile_a, t_pile **pile_b, t_pile *cheapest_node)
{
	while (*pile_a != cheapest_node->target && *pile_b != cheapest_node)
		make_rr(pile_a, pile_b);
	current_pos(*pile_a);
	current_pos(*pile_b);
}

void	reverse_rotate_both(t_pile **pile_a, t_pile **pile_b, 
							t_pile *cheapest_node)
{
	while (*pile_a != cheapest_node->target && *pile_b != cheapest_node)
		make_rrr(pile_a, pile_b);
	current_pos(*pile_a);
	current_pos(*pile_b);
}

void	final_rotations(t_pile **pile, t_pile *top, char pile_x)
{
	while (*pile != top)
	{
		if (pile_x == 'a')
		{
			if (top->above_median)
				make_ra(pile);
			else
				make_rra(pile);
		}
		else if (pile_x == 'b')
		{
			if (top->above_median)
				make_rb(pile);
			else
				make_rrb(pile);
		}
	}
}

void	move_nodes(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;

	cheapest = give_cheapest(*pile_b);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(pile_a, pile_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		reverse_rotate_both(pile_a, pile_b, cheapest);
	final_rotations(pile_b, cheapest, 'b');
	final_rotations(pile_a, cheapest->target, 'a');
	make_pa(pile_a, pile_b);
}

void	push_swap(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*smallest;
	int		len_a;

	len_a = ft_lstsize(*pile_a);
	if (len_a == 5)
		sort_five(pile_a, pile_b);
	else
	{
		while (len_a-- > 3)
			make_pb(pile_a, pile_b);
	}
	mini_algo(pile_a);
	while (*pile_b)
	{
		init_nodes(*pile_a, *pile_b);
		move_nodes(pile_a, pile_b);
	}
	current_pos(*pile_a);
	smallest = find_small(*pile_a);
	if (smallest->above_median)
		while (*pile_a != smallest)
			make_ra(pile_a);
	else
		while (*pile_a != smallest)
			make_rra(pile_a);
}
