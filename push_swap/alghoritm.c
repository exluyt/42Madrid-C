/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:43:26 by akiss             #+#    #+#             */
/*   Updated: 2025/02/18 13:29:20 by akiss            ###   ########.fr       */
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
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
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
		pb(a, b, true);
	if(len_a-- > 3 && !stack_ordered(*a))
		pb(a, b, true);
	while(len_a-- > 3 && !stack_ordered(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_small(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a, );
}

void set_target_a(t_slack *a, t_slack *b)
{
	t_slack *current_b;
	t_slack *target_node;
	long	best_target;

	while(a)
	{
		best_target = LONG_MIN;
		current_b = b;
		while(current_b)
		{
			if(current_b->value < a->value && current_b->value > best_target)
			{
				best_target = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_target == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void cost_analysis_a(t_slack *a, t_slack *b)
{
	int len_a;
	int len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while(a)
	{
		a->cost = a->index;
		if(!(a->above_median))
			a->cost = len_a - (a->index);
		if(a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}