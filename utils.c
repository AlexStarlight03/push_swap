/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:33:27 by alexandrine       #+#    #+#             */
/*   Updated: 2023/07/27 11:36:50 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		n;
	long	res;

	i = 0;
	res = 0;
	n = 1;
	if ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			n *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * n);
}

t_pile	*find_highest(t_pile *pile)
{
	int		highest;
	t_pile	*highest_node;

	if (pile == NULL)
		return (NULL);
	highest = INT_MIN;
	while (pile)
	{
		if (pile->value > highest)
		{
			highest = pile->value;
			highest_node = pile;
		}
		pile = pile->next;
	}
	return (highest_node);
}

t_pile	*find_small(t_pile *pile)
{
	long	smallest;
	t_pile	*smallest_node;

	if (pile == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (pile)
	{
		if (pile->value < smallest)
		{
			smallest = pile->value;
			smallest_node = pile;
		}
		pile = pile->next;
	}
	return (smallest_node);
}

void	add_node(t_pile **pile, int nb)
{
	t_pile	*node;
	t_pile	*last_node;

	if (pile == NULL)
		return ;
	node = malloc(sizeof(t_pile));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nb;
	if (*pile == NULL)
	{
		*pile = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*pile);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	pile_init(t_pile **pile_a, char **argv, bool flag_argc_2)
{
	long	nb;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(pile_a, argv, flag_argc_2);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_free(pile_a, argv, flag_argc_2);
		if (error_rep(*pile_a, (int)nb))
			error_free(pile_a, argv, flag_argc_2);
		add_node(pile_a, (int)nb);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
