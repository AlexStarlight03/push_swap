/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_mng.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:45:41 by alexandrine       #+#    #+#             */
/*   Updated: 2023/08/01 09:36:59 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_pile(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*current;

	if (pile == NULL)
		return ;
	current = *pile;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*pile = NULL;
}

void	error_free(t_pile **pile_a, char **argv, bool flag_argc_2)
{
	free_pile(pile_a);
	if (flag_argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit (1);
}

int	error_syntax(char *nb)
{
	if (!(*nb == '-' || *nb == '+' || (*nb >= '0' && *nb <= '9')))
		return (1);
	if ((*nb == '-' || *nb == '+') && !(nb[1] >= '0' && nb[1] <= '9'))
		return (1);
	while (*++nb)
	{
		if (!(*nb >= '0' && *nb <= '9'))
			return (1);
	}
	return (0);
}

int	error_rep(t_pile *pile_a, int nb)
{
	if (pile_a == NULL)
		return (0);
	while (pile_a)
	{
		if (pile_a->value == nb)
			return (1);
		pile_a = pile_a->next;
	}
	return (0);
}
