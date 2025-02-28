/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaciones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:40:17 by akiss             #+#    #+#             */
/*   Updated: 2025/02/24 12:32:32 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_slack **a, bool print)
{
	t_slack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_slack **b, bool print)
{
	t_slack	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_slack **a, t_slack **b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		ft_printf("ss\n");
}

void	pa(t_slack **a, t_slack **b, bool print)
{
	t_slack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	ft_lstadd_front(a, tmp);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_slack **a, t_slack **b, bool print)
{
	t_slack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	ft_lstadd_front(b, tmp);
	if (print)
		ft_printf("pb\n");
}
