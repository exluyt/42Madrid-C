/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:44:21 by akiss             #+#    #+#             */
/*   Updated: 2024/12/08 18:56:12 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/libft/libft.h"
#include "./ft_printf/ft_printf.h"

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
typedef struct s_slack
{
	int				*value;
	struct s_slack	*next;
}				t_slack;

void    sa(t_slack **a);
void    sb(t_slack **ab);
void    ss(t_slack **a, t_slack **b);
void    pa(t_slack **a, t_slack **b);
void    pb(t_slack **a, t_slack **b);
void    ra(t_slack **a);
void    rb(t_slack **b);
void    rr(t_slack **a, t_slack **b);
void   rra(t_slack **a);
void    rrb(t_slack **b);
void    rrr(t_slack **a, t_slack **b);
#endif