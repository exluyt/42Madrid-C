/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaciones_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:20:20 by akiss             #+#    #+#             */
/*   Updated: 2025/02/24 10:16:58 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_slack **a, bool print)
{
    t_slack *tmp;
    
    if (*a == NULL || (*a)->next == NULL)
        return; 
    
    tmp = *a;
    *a = (*a)->next;
    tmp->next = NULL;
    ft_lstadd_back(a, tmp);
    if(print)
    {
        ft_printf("ra\n");
    }    
}

void rb(t_slack **b, bool print)
{
    t_slack *tmp;
    
    if (*b == NULL || (*b)->next == NULL)
        return;
    
    tmp = *b;
    *b = (*b)->next;
    tmp->next = NULL;
    ft_lstadd_back(b, tmp);
    if(print)
    {
        ft_printf("rb\n");
    }
}

void rr(t_slack **a, t_slack **b, bool print)
{
    ra(a, false);
    rb(b, false);
    if(print)
    {
        ft_printf("rr\n");
    }
}

void rra(t_slack **a, bool print)
{
    t_slack *tmp;
    t_slack *prev;

    if (*a == NULL || (*a)->next == NULL)
        return;
    tmp = *a;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    prev = tmp;
    tmp = tmp->next;
    prev->next = NULL;
    tmp->next = *a;
    *a = tmp;
    if(print)
    {
        ft_printf("rra\n");
    }
}

void rrb(t_slack **b, bool print)
{
    t_slack *tmp;
    t_slack *prev;

    if (*b == NULL || (*b)->next == NULL)
        return;
    tmp = *b;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    prev = tmp;
    tmp = tmp->next;
    prev->next = NULL;
    tmp->next = *b;
    *b = tmp;
    if(print)
    {
        ft_printf("rrb\n");
    }
}