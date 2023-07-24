/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:32:01 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/24 16:32:15 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_pile *pile)
{
    int    temp;

    if (pile == NULL || pile->next == NULL)
        return;
    temp = pile->value;
    pile->value = pile->next->value;
    pile->next->value = temp;

}

void    make_sa(t_pile **pile_a)
{
    swap(*pile_a);
    ft_putstr_fd("sa\n", 1);
}

void    make_sb(t_pile **pile_b)
{
    swap(*pile_b);
    ft_putstr_fd("sb\n", 1);
} 

void    make_ss(t_pile **pile_a, t_pile **pile_b)
{
    swap(*pile_a);
    swap(*pile_b);
    ft_putstr_fd("ss\n", 1);    
}