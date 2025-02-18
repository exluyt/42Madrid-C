/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:44:21 by akiss             #+#    #+#             */
/*   Updated: 2025/02/18 13:28:39 by akiss            ###   ########.fr       */
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
void seat_cheapest(t_slack *slack);
int	ft_atol(const char *nptr);
void append_node(t_slack **slack, int n);
bool stack_ordered(t_slack *slack);
void current_index(t_slack *slack);
void init_nodes_a(t_slack *a, t_slack *b);
void move_a_to_b(t_slack **a, t_slack **b);
void move_b_to_a(t_slack **a, t_slack **b);
void min_on_top(t_slack **a, t_slack **b);
void rotate_both(t_slack **a, t_slack **b, t_slack *cheapest);
void prep_for_push(t_slack **stack, t_slack *top_node, char stack_name);
void	create_stack_a(t_slack **a, char **argv);
void sort_small(t_slack **a);
void ft_turk(t_slack **a, t_slack **b);
void set_target_a(t_slack *a, t_slack *b);
void cost_analysis_a(t_slack *a, t_slack *b);
void init_nodes_b(t_slack *a, t_slack *b);
void set_target_b(t_slack *a, t_slack *b);
void move_b_to_a(t_slack **a, t_slack **b);
t_slack	*find_min(t_slack *stack);
void	free_errors(t_slack **a);
void	free_stack(t_slack **stack);
int	error_syntax(char *str_n);
int	error_duplicate(t_slack *a, int n);


#endif