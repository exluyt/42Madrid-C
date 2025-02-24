/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:26:55 by akiss             #+#    #+#             */
/*   Updated: 2025/02/19 13:04:23 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_slack *lst, void (*del)(void*))
{
    int *value_ptr;

    value_ptr = &(lst->value);
    del(value_ptr);
    free(lst);
}
