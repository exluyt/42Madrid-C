/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:04:55 by akiss             #+#    #+#             */
/*   Updated: 2025/03/02 21:16:21 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initialize_forks(struct s_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		data->philosophers[i].left_fork = &forks[i];
		data->philosophers[i].right_fork = &forks[i + 1];
		i++;
	}
}

void	ft_initialize_data(char **argv, struct s_data *data, int argc)
{
	pthread_mutex_t		forks[atoi(argv[1])];
	
	ft_initialize_forks(data, forks);
	data->num_philosophers = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->num_times_to_eat = -1;
	if (argc == 5)
		data->num_times_to_eat = atoi(argv[5]);
	pthread_t philosophers[data->num_philosophers];
	ft_create_threads(data, philosophers);
}

int main(int argc, char **argv)
{
	struct s_data data; 

	if(argc < 5 && argc > 7)
	{
		printf("Error: Not enough arguments\n");
		return (EXIT_FAILURE);
	} else
		ft_initialize_data(argv, &data, argc);
	return (EXIT_SUCCESS);
}
