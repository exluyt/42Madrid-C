/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:53:24 by akiss             #+#    #+#             */
/*   Updated: 2024/07/14 11:18:27 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int main(void)
{
    int *range = NULL;
    int range_size = ft_ultimate_range(&range, 0, 1); 

    printf("Range size: %d\n", range_size);
    for (int i = 0; i < range_size; i++)
    {
        printf("%d ", range[i]); 
    }
    printf("\n");

    free(range); 
    return 0;
}
*/