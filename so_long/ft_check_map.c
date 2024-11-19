/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:39:00 by akiss             #+#    #+#             */
/*   Updated: 2024/11/19 13:36:21 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_map(char **map, t_vars var)
{
	char **copy;
	int	i;

	i = 0;
	copy = malloc((var.height + 1) * sizeof(char *));
	if (!copy)
		return (EXIT_FAILURE);
	copy[var.height] = NULL;
	while(i < var.height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
}

int	ft_so_long(char **map, t_vars var)
{
    int		j;
    size_t	line_length;

    if (!map || !map[0])
        return (EXIT_FAILURE);

    line_length = ft_strlen(map[0]);

    j = 1;
    while (j < var.height - 1)
    {
        if (ft_strlen(map[j]) != line_length)
            return (EXIT_FAILURE);
        j++;
    }
	if (ft_strlen(map[var.height - 1]) != line_length - 1)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int	ft_is_c(char **map, t_vars var)
{
	int	i;
	int	j;
	int	countC;

	countC = 0;
	j = 0;
	while (j < var.height)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'C')
				countC++;
			i++;
		}
		j++;
	}
	if (countC < 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_is_one_p_e(char **map, t_vars var)
{
	int	i;
	int	j;
	int	countP;
	int	countE;

	countP = 0;
	countE = 0;
	j = 0;
	while (j < var.height)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'P')
				countP++;
			if (map[j][i] == 'E')
				countE++;
			i++;
		}
		j++;
	}
	if (countP != 1 || countE != 1)
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
	if (ft_is_one_row(map, var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (ft_is_one_column(map, var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (ft_is_one_p_e(map, var))
		return (EXIT_FAILURE);
	else if (ft_is_c(map, var))
		return (EXIT_FAILURE);
	else if (ft_so_long(map, var))
		return (EXIT_FAILURE);
	else if (ft_fill_map(map, var))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
