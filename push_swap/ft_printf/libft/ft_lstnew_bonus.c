/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:38:01 by akiss             #+#    #+#             */
/*   Updated: 2025/02/19 13:03:43 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slack	*ft_lstnew(void *content)
{
	t_slack	*new;

	new = (t_slack *)malloc(sizeof(t_slack));
	if (new == NULL)
		return (NULL);
	new->value = *(int *)content;
	new->next = NULL;
	return (new);
}
