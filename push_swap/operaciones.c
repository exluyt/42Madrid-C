/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaciones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:40:17 by akiss             #+#    #+#             */
/*   Updated: 2024/12/08 18:19:08 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_slack **a)
{
	t_slack *tmp;

	if (*a == NULL || (*a)->next == NULL)
		return;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void sb(t_slack **b)
{
	t_slack *tmp;

	if (*b == NULL || (*b)->next == NULL)
		return;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
}

void ss(t_slack **a, t_slack **b)
{
	sa(a);
	sb(b);
}

void pa(t_slack **a, t_slack **b)
{
	t_slack *tmp;

	if (*b == NULL)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	ft_lstadd_front(a, tmp);
}
void pb(t_slack **a, t_slack **b)
{
	t_slack *tmp;

	if (*a == NULL)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	ft_lstadd_front(b, tmp);
}
