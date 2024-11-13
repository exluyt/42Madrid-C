/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:39:00 by akiss             #+#    #+#             */
/*   Updated: 2024/11/03 19:18:07 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_calc_width_map(char **map)
{
    int width;
	
	width = 0;
    while (map[width] != NULL)
        width++;
    return width;
}

int	ft_check_map(char **map)
{
    int i;
    int j;
    int width;

	j = 0;
	i = 0;
    if (!map || !map[0])
        return (0);

    width = ft_calc_width_map(map);

    i = 0;
    while (map[0][i] != '\0')
    {
        if (map[0][i] != '1' || map[width - 1][i] != '1')
            return (0);
        i++;
    }
	return (1);
}