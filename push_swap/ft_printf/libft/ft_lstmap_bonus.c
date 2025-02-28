/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:48:18 by akiss             #+#    #+#             */
/*   Updated: 2025/02/19 13:05:23 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slack	*ft_lstmap(t_slack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_slack	*new_lst;
	t_slack	*new_elem;
	void	*temp;

	new_lst = NULL;
	while (lst)
	{
		temp = f(&(lst->value));
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_elem = ft_lstnew(temp);
		if (!new_elem)
		{
			del(temp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
