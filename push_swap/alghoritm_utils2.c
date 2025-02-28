/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:25:13 by akiss             #+#    #+#             */
/*   Updated: 2025/02/24 12:36:40 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_slack *slack)
{
	long	cheapest_value;
	t_slack	*cheapest_node;

	if (!slack)
		return ;
	cheapest_value = LONG_MAX;
	while (slack)
	{
		if (slack->cost < cheapest_value)
		{
			cheapest_value = slack->cost;
			cheapest_node = slack;
		}
		slack = slack->next;
	}
	cheapest_node->cheapest = true;
}

void	move_a_to_b(t_slack **a, t_slack **b)
{
	t_slack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target, 'b');
	pb(a, b, true);
}

void	min_on_top(t_slack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	rotate_both(t_slack **a, t_slack **b, t_slack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	prep_for_push(t_slack **stack, t_slack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
