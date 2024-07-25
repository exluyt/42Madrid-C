/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:14:54 by akiss             #+#    #+#             */
/*   Updated: 2024/07/14 09:55:22 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	range = malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
/*
#include <stdio.h>
int	main(void)
{
	int *range = ft_range(-5, -1);
	int i = 0;
	while (i < 4)
	{
		printf("%d\n", range[i]);
		i++;
	}
	free(range);
	return (0);
}
*/