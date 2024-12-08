/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:56:47 by akiss             #+#    #+#             */
/*   Updated: 2024/12/08 20:47:19 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putnbr_wrapper(void *value)
{
    ft_putnbr(*(int *)value, 1);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    t_slack *slack_a;
    t_slack *slack_b;
    int *value;
    int move_count = 0;

    slack_a = NULL;
    slack_b = NULL;
    while (argc > 1)
    {
        value = malloc(sizeof(int));
        if (value == NULL)
            return (free(slack_a), free(slack_b), EXIT_FAILURE);
        *value = ft_atoi(argv[argc - 1]);
        ft_lstadd_front(&slack_a, ft_lstnew(value));
        argc--;
    }

    ft_lstiter(slack_a, ft_putnbr_wrapper);
    // ft_printf("Total moves: %d\n", move_count);
    return (0);
}