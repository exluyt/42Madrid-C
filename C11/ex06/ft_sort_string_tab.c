/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:51:39 by akiss             #+#    #+#             */
/*   Updated: 2024/07/24 02:23:30 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_swap(char *buffer[], int i, int min)
{
	char	*temp;

	temp = buffer[i];
	buffer[i] = buffer[min];
	buffer[min] = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		min;
	int		len;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	while (i < len - 1)
	{
		j = i + 1;
		min = i;
		while (j < len)
		{
			if (ft_strcmp(tab[min], tab[j]) > 0)
				min = j;
			j++;
		}
		if (ft_strcmp(tab[i], tab[min]) > 0)
			ft_swap(tab, i, min);
		i++;
	}
}

/* 
#include <stdio.h>
int main(void)
{
    char *tab[] = {"hola", "adios", 
	"buenos dias", "buenas noches", "buenas tardes", 
	"buenas madrugadas", "buenas noches", (void *) 0};
    ft_sort_string_tab(tab);

    for (int i = 0; tab[i] != (void *)0; i++) {
        printf("%s\n", tab[i]);
    }

    return 0;
}
 */