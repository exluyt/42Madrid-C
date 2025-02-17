/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:44:21 by akiss             #+#    #+#             */
/*   Updated: 2025/02/17 21:18:46 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdbool.h>
#include <limits.h>
#include "./ft_printf/libft/libft.h"
#include "./ft_printf/ft_printf.h"

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
typedef struct s_slack
{
	int				value;
	int 			index;
	int 			cost;
	bool			above_median;
	bool			cheapest;
	struct s_slack	*target;
	struct s_slack	*next;
	struct s_slack	*prev;
}				t_slack;

void    sa(t_slack **a, bool print);
void    sb(t_slack **ab, bool print);
void    ss(t_slack **a, t_slack **b, bool print);
void    pa(t_slack **a, t_slack **b, bool print);
void    pb(t_slack **a, t_slack **b, bool print);
void    ra(t_slack **a, bool print);
void    rb(t_slack **b, bool print);
void    rr(t_slack **a, t_slack **b, bool print);
void   rra(t_slack **a, bool print);
void    rrb(t_slack **b, bool print);
void    rrr(t_slack **a, t_slack **b, bool print);

#endif