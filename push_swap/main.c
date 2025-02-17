/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:56:47 by akiss             #+#    #+#             */
/*   Updated: 2025/02/17 21:19:06 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_slack *slack_a;
    t_slack *slack_b;
    
    slack_a = NULL;
    slack_b = NULL;

    if(argc == 1 || (argc == 2 && !argv[1][0]))
        return (EXIT_FAILURE);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    create_stack_a(&slack_a, argv + 1);
    if(!stack_ordered(slack_a))
    {
        if (stack_len(slack_a) == 2)
            sa(&slack_a, true);
        else if (stack_len(slack_a) == 3)
            sort_small(&slack_a);
        else
            ft_turk(&slack_a, &slack_b);
    }
    free_stack(slack_a);
    return (0);
}
