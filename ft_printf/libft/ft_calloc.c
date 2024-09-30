/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:53:09 by akiss             #+#    #+#             */
/*   Updated: 2024/09/25 10:21:16 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot_size;
	void	*pointer;

	tot_size = nmemb * size;
	pointer = malloc(tot_size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, tot_size);
	return (pointer);
}
