/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:29:52 by akiss             #+#    #+#             */
/*   Updated: 2024/09/26 11:37:22 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_putnbr(int nb, int fd);
int		ft_putstr(char *s, int fd);
int		ft_putchar(char c, int fd);
int		ft_printf(const char *format, ...);
int		ft_putaddr(unsigned long long number, int fd);
int		ft_puthex_lo_fd(unsigned int nbr, int fd);
int		ft_puthex_up_fd(unsigned long long nbr, int fd);
int		ft_putnbr_u(unsigned int nb, int fd);

#endif