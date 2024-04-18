/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:08:46 by lissam            #+#    #+#             */
/*   Updated: 2024/04/18 11:34:21 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(long milliseconds)
{
	long	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	number_of_meals_counter(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_time);
	if (philo->number_of_meals < philo->data->times_must_eat)
		philo->number_of_meals++;
	pthread_mutex_unlock(philo->data->lock_time);
}

int	join_destroy(t_data *data, t_philo *philos, t_mutex *mutexes)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_join(philos[i++].t, NULL))
		{
			error_pthread_create();
			return (1);
		}
	}
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_destroy(&mutexes[i++].mutex))
		{
			error_mutex_destroy();
			return (1);
		}
	}
	return (0);
}
