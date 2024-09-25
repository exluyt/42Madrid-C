/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:48:18 by akiss             #+#    #+#             */
/*   Updated: 2024/09/25 10:56:08 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*temp;

	new_lst = NULL;
	new_elem = NULL;
	temp = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (temp)
			temp->next = new_elem;
		else
			new_lst = new_elem;
		temp = new_elem;
		lst = lst->next;
	}
	return (new_lst);
}
/* 
int main ()
{
	t_list *lst = ft_lstnew("Hola");
	t_list *lst2 = ft_lstnew("Mundo");
	t_list *lst3 = ft_lstnew("Cruel");
	lst->next = lst2;
	lst2->next = lst3;
	t_list *lst4 = ft_lstmap(lst, ft_strdup, free);
	while (lst4)
	{
		printf("%s\n", lst4->content);
		lst4 = lst4->next;
	}
	return 0;
}
*/