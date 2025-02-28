/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:00:52 by akiss             #+#    #+#             */
/*   Updated: 2025/02/24 12:35:17 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_b(t_slack *a, t_slack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	set_target_b(t_slack *a, t_slack *b)
{
	t_slack	*current_a;
	t_slack	*target_node;
	long	best_target;

	while (b)
	{
		best_target = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_target)
			{
				best_target = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_target == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	move_b_to_a(t_slack **a, t_slack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, true);
}

t_slack	*find_min(t_slack *stack)
{
	long	min;
	t_slack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_slack	*find_max(t_slack *stack)
{
	long	max;
	t_slack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
