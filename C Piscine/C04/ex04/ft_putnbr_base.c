/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:25:48 by akiss             #+#    #+#             */
/*   Updated: 2024/07/10 13:01:50 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		base_len;

	if (!check_base(base))
		return ;
	num = nbr;
	base_len = ft_strlen(base);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= base_len)
	{
		ft_putnbr_base(num / base_len, base);
		ft_putnbr_base(num % base_len, base);
	}
	else
	{
		write(1, &base[num], 1);
	}
}
/*
int main()
{
	char base[] = "01";
	ft_putnbr_base(123456, base);
	return 0;
}
*/