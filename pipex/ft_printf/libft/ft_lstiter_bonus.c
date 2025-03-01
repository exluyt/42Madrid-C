/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:47:20 by akiss             #+#    #+#             */
/*   Updated: 2025/02/24 12:26:01 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_slack *lst, void (*f)(void *))
{
	int	*value_ptr;

	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		value_ptr = &(lst->value);
		f(value_ptr);
		lst = lst->next;
	}
}
