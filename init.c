/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:20:01 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/24 16:08:40 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    current_pos(t_pile *pile)
{
    int i;
    int middle;

    i = 0;
    if (pile == NULL)
        return ;
    middle = ft_lstsize(pile) / 2;
    while (pile)
    {
        pile->current_pos = i;
        if (i <= middle)
            pile->above_median = true;
        else 
            pile->above_median = false;
        pile = pile->next;
        i++;
    }
}

void    find_target(t_pile *pile_a, t_pile *pile_b)
{
    long    best;
    t_pile  *current_a;
    t_pile  *target;

    while (pile_b)
    {
        best = LONG_MAX;
        current_a = pile_a;
        while (current_a)
        {
            if ((current_a->value > pile_b->value) && (current_a->value < best))
            {
                best = current_a->value;
                target = current_a;
            }
            current_a = current_a->next;
        }
        if (best == LONG_MAX)
            pile_b->target = find_small(pile_a);
        else
            pile_b->target = target;
        pile_b = pile_b->next;
    }
}

void    price_move(t_pile *pile_a, t_pile *pile_b)
{
    int len_a;
    int len_b;

    len_a = ft_lstsize(pile_a);
    len_b = ft_lstsize(pile_b);
    while (pile_b)
    {
        pile_b->move_price = pile_b->current_pos;
        if (!(pile_b->above_median))
            pile_b->move_price = len_b - (pile_b->current_pos);
        if (pile_b->target->above_median)
            pile_b->move_price += pile_b->target->current_pos;
        else
            pile_b->move_price += len_a - (pile_b->target->current_pos);
        pile_b = pile_b->next;
    }
}

void    cheapest_move(t_pile *pile_b)
{
    long    best_move;
    t_pile  *best_move_node;

    if (pile_b == NULL)
        return ;
    best_move = LONG_MAX;
    while (pile_b)
    {
        if (pile_b->move_price < best_move)
        {
            best_move = pile_b->move_price;
            best_move_node = pile_b;
        }
        pile_b = pile_b->next;
    }
    best_move_node->cheapest = true;
}

void    init_nodes(t_pile *pile_a, t_pile *pile_b)
{
    current_pos(pile_a);
    current_pos(pile_b);
    find_target(pile_a, pile_b);
    price_move(pile_a, pile_b);
    cheapest_move(pile_b);
}