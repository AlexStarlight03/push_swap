/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:28:21 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/24 16:27:57 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

long ft_atol(const char *nptr);
t_pile  *find_highest(t_pile *pile);
t_pile  *find_small(t_pile *pile);
void    add_node(t_pile **pile, int nb);
void    pile_init(t_pile **pile_a, char **argv, bool flag_argc_2);
void    swap(t_pile *pile);
void    make_sa(t_pile **pile_a);
void    make_sb(t_pile **pile_b);
void    make_ss(t_pile **pile_a, t_pile **pile_b);
void    rotate(t_pile **pile);
void    make_ra(t_pile **pile_a);
void    make_rb(t_pile **pile_b);
void    make_rr(t_pile **pile_a, t_pile **pile_b);
t_pile	*get_before_tail(t_pile *pile);
void    reverse_rotate(t_pile **pile);
void    make_rra(t_pile **pile_a);
void    make_rrb(t_pile **pile_b);
void    make_rrr(t_pile **pile_a, t_pile **pile_b);
void    push(t_pile **src, t_pile **dest);
void    make_pa(t_pile **pile_a, t_pile **pile_b);
void    make_pb(t_pile **pile_a, t_pile **pile_b);
t_pile  *give_cheapest(t_pile *pile);
void    move_nodes(t_pile **pile_a, t_pile **pile_b);
void    push_swap(t_pile **pile_a, t_pile **pile_b);
bool    is_sorted(t_pile *pile);
void    mini_algo(t_pile **pile);
void    sort_five(t_pile **pile_a, t_pile **pile_b);
int     main(int argc, char **argv);
void    current_pos(t_pile *pile);
void    find_target(t_pile *pile_a, t_pile *pile_b);
void    price_move(t_pile *pile_a, t_pile *pile_b);
void    cheapest_move(t_pile *pile_b);
void    init_nodes(t_pile *pile_a, t_pile *pile_b);
void    free_matrix(char **argv);
void    free_pile(t_pile **pile);
void    error_free(t_pile **pile_a, char **argv, bool flag_argc_2);
int     error_syntax(char *nb);
int     error_rep(t_pile *pile_a, int nb);
void    rotate_both(t_pile **pile_a, t_pile **pile_b, t_pile *cheapest_node);
void    reverse_rotate_both(t_pile **pile_a, t_pile **pile_b, t_pile *cheapest_node);
void    final_rotations(t_pile **pile, t_pile *top, char pile_x);

#endif