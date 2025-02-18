/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghoritm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:40:29 by akiss             #+#    #+#             */
/*   Updated: 2025/02/18 12:10:44 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *nptr)
{
	long	result;
	long	sign;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void append_node(t_slack **slack, int n)
{
    t_slack *node;
    t_slack *last;

    if (!slack)
        return ;
    node = malloc(sizeof(t_slack));
    if (!node)
        return ;
    node->next = NULL;
    node->value = n;
    if(!(*slack))
    {
        *slack = node;
        node->prev = NULL;
    }
    else
    {
        last = ft_lstlast(*slack);
        last->next = node;
        node->prev = last;
    }
}
bool stack_ordered(t_slack *slack)
{
    if (!slack)
        return (true);
    while (slack->next)
    {
        if (slack->value > slack->next->value)
            return (false);
        slack = slack->next;
    }
    return (true);
}

void current_index(t_slack *slack)
{
    int i;
    int median;

    i = 0;
    if(!slack)
        return ;
    median = ft_lstsize(slack) / 2;
    while(slack)
    {
        slack->index = i;
        if(i <= median)
            slack->above_median = true;
        else
            slack->above_median = false;
        slack = slack->next;
        ++i;
    }
}

void init_nodes_a(t_slack *a, t_slack *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis_a(a, b);
    set_cheapest_a(a);
}
