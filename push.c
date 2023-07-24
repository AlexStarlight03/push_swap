/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:32:39 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/24 16:31:05 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_pile **src, t_pile **dest)
{
    t_pile  *temp;

    if (*src == NULL)
        return;
    temp = (*src)->next;
    (*src)->next = *dest;
    *dest = *src;
    *src = temp;
}

void    make_pa(t_pile **pile_a, t_pile **pile_b)
{
    push(pile_b, pile_a);
    ft_putstr_fd("pa\n", 1);
}

void    make_pb(t_pile **pile_a, t_pile **pile_b)
{
    push(pile_a, pile_b);
    ft_putstr_fd("pb\n", 1);
}