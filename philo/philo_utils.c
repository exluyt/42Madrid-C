/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:40:30 by akiss             #+#    #+#             */
/*   Updated: 2025/03/02 21:11:49 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philosopher *philosopher;
	
	philosopher = (t_philosopher *)arg;
	struct timeval time;
	struct timeval end_time;
	while (1) {
		gettimeofday(&time, NULL);
		printf("%ld %d %s", time.tv_sec * 1000, philosopher->id, "is thinking\n");
			
		gettimeofday(&time, NULL);
		while (pthread_mutex_lock(philosopher->left_fork) != 0)
		{
			gettimeofday(&end_time, NULL);
			if (end_time.tv_sec - time.tv_sec > philosopher->data->time_to_die)
			{
				printf("%ld %d %s", time.tv_sec * 1000, philosopher->id, "died\n");
				return (NULL);
			}
		}
		gettimeofday(&time, NULL);
		printf("%ld %d %s", time.tv_sec * 1000, philosopher->id, "has taken a fork\n");
	
		pthread_mutex_lock(philosopher->right_fork);
		gettimeofday(&time, NULL);
		printf("%ld %d %s", time.tv_sec * 1000, philosopher->id, "has taken a fork\n");
		gettimeofday(&time, NULL);
	
		printf("%ld %d %s", time.tv_sec * 1000, philosopher->id, "is eating\n");
		usleep(philosopher->data->time_to_eat);
		

		pthread_mutex_unlock(philosopher->right_fork);
		pthread_mutex_unlock(philosopher->left_fork);
	
		gettimeofday(&time, NULL);
		printf("%ld %d %s", time.tv_sec * 1000, philosopher->id, "is sleeping\n");
		usleep(philosopher->data->time_to_sleep);
		if (philosopher->data->time_to_eat == 0)
		{
			gettimeofday(&time, NULL);
			printf("%ld %d %s", time.tv_sec * 1000, philosopher->id, "is thinking\n");
			usleep(philosopher->data->time_to_die);
			gettimeofday(&time, NULL);
			printf("%ld %d %s", time.tv_sec * 1000, philosopher->id, "died\n");
			break;
		}
	}
	return (NULL);
}

void	ft_create_threads(t_data *data, pthread_t *philosophers)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_create(&philosophers[i], NULL, &ft_routine, &data->philosophers[i]);
		pthread_detach(philosophers[i]);
		i++;
	}
}
