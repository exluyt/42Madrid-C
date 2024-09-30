/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:17:45 by akiss             #+#    #+#             */
/*   Updated: 2024/09/26 10:16:29 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_up_fd(unsigned long long nbr, int fd)
{
	char	*base;
	int		size;

	base = "0123456789ABCDEF";
	size = 0;
	if (nbr == 0)
		size += write(fd, "0", 1);
	else
	{
		if (nbr >= 16)
			size += ft_puthex_up_fd(nbr / 16, fd);
		size += write(fd, &base[nbr % 16], 1);
	}
	return (size);
}
