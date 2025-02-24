/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:47:20 by akiss             #+#    #+#             */
/*   Updated: 2025/02/19 13:04:53 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_slack *lst, void (*f)(void *))
{
    if (lst == NULL)
        return ;
    while (lst != NULL)
    {
        int *value_ptr = &(lst->value);
        f(value_ptr);
        lst = lst->next;
    }
}
