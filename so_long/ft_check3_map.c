/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:23:45 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 16:28:11 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_all_chr(char **map, t_vars var)
{
	int	i;
	int	j;

	j = 0;
	while (j < var.height)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'P'
				&& map[j][i] != 'E' && map[j][i] != 'C' && map[j][i] != 'J'
				&& map[j][i] != '\n')
				return (EXIT_FAILURE);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
