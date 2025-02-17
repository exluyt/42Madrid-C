/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:43:26 by akiss             #+#    #+#             */
/*   Updated: 2025/02/17 21:22:45 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack_a(t_slack **a, char **argv)
{
	int	n;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_error(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (error_duplicate(*a, (int)n))
			free_error(a);
		append(a, (int)n);
		i++;
	}
}

void sort_small(t_slack **a)
{
	t_slack *big;

	big = find_max(*a);
	if (big == *a)
		ra(a, true);
	else if ((*a)->next == big)
		rra(a, true);
	if((*a)->value > (*a)->next->value)
		sa(a, true);
}

void ft_turk(t_slack **a, t_slack **b)
{
	int len_a;
	
	len_a = ft_lstsize(*a);
	if(len_a-- > 3 && !stack_ordered(*a))
	{
	}
}