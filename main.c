/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:31:53 by alexandrine       #+#    #+#             */
/*   Updated: 2023/08/01 09:32:12 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (argc == 1 || (argc == 1 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], 32);
		if (!argv[1])
			ft_free(argv, 1);
	}
	pile_init(&pile_a, argv + 1, argc == 2);
	if (!is_sorted(pile_a))
	{
		if (ft_lstsize(pile_a) == 2)
			make_sa(&pile_a);
		else if (ft_lstsize(pile_a) == 3)
			mini_algo(&pile_a);
		else
			push_swap(&pile_a, &pile_b);
	}
	free_pile(&pile_a);
}
