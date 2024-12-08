/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaciones_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:20:20 by akiss             #+#    #+#             */
/*   Updated: 2024/12/08 18:54:34 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_slack **a)
{
    t_slack *tmp;
    
    tmp = *a;
    *a = (*a)->next;
    tmp->next = NULL;
    ft_lstadd_back(a, tmp);
}

void rb(t_slack **b)
{
    t_slack *tmp;
    
    tmp = *b;
    *b = (*b)->next;
    tmp->next = NULL;
    ft_lstadd_back(b, tmp);
}

void rr(t_slack **a, t_slack **b)
{
    ra(a);
    rb(b);
}

void rra(t_slack **a)
{
    t_slack *tmp;
    t_slack *prev;

    tmp = *a;
    while (tmp->next->next != NULL)
        tmp = tmp->next;

    prev = tmp;
    tmp = tmp->next;
    prev->next = NULL;
    tmp->next = *a;
    *a = tmp;
}

void rrb(t_slack **b)
{
    t_slack *tmp;
    t_slack *prev;

    tmp = *b;
    while (tmp->next->next != NULL)
        tmp = tmp->next;

    prev = tmp;
    tmp = tmp->next;
    prev->next = NULL;
    tmp->next = *b;
    *b = tmp;
}