/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:26:55 by akiss             #+#    #+#             */
/*   Updated: 2025/02/24 12:26:05 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_slack *lst, void (*del)(void*))
{
	int	*value_ptr;

	value_ptr = &(lst->value);
	del(value_ptr);
	free(lst);
}
