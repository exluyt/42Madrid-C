/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:06:09 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 16:23:30 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_c(char **map, t_vars var)
{
	int	i;
	int	j;
	int	count_c;

	count_c = 0;
	j = 0;
	while (j < var.height)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'C')
				count_c++;
			i++;
		}
		j++;
	}
	if (count_c < 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_is_one_p_e(char **map, t_vars var)
{
	int	i;
	int	j;
	int	count_p;
	int	count_e;

	count_p = 0;
	count_e = 0;
	j = 0;
	while (j < var.height)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'P')
				count_p++;
			if (map[j][i] == 'E')
				count_e++;
			i++;
		}
		j++;
	}
	if (count_p != 1 || count_e != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_is_one_row(char **map, t_vars var)
{
	int	i;

	i = 0;
	while (i < var.width)
	{
		if (map[0][i] != '1' || map[var.height - 1][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_is_one_column(char **map, t_vars var)
{
	int	j;

	j = 0;
	while (j < var.height)
	{
		if (map[j][0] != '1' || map[j][var.width - 1] != '1')
			return (EXIT_FAILURE);
		j++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_map(char **map, t_vars var)
{
	if (!map || !map[0])
		return (EXIT_FAILURE);
	if (ft_all_chr(map, var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (ft_is_one_row(map, var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (ft_is_one_column(map, var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (ft_is_one_p_e(map, var))
		return (EXIT_FAILURE);
	else if (ft_is_c(map, var))
		return (EXIT_FAILURE);
	else if (ft_so_long(map, var))
		return (EXIT_FAILURE);
	else if (is_map_solvable(map, var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
