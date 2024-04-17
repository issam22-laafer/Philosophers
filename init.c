/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:19 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 21:49:08 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *data, t_philo *philo, t_mutex *mutexes, int i)
{
	philo->number_of_meals = 0;
	philo->id = i + 1;
	philo->data = data;
	philo->last_time_eat = get_current_time();
	if (i % 2)
	{
		philo->left = &mutexes[i].mutex;
		philo->right = &mutexes[(i + 1) % data->n_philos].mutex;
	}
	else
	{
		philo->left = &mutexes[(i + 1) % data->n_philos].mutex;
		philo->right = &mutexes[i].mutex;
	}
}

int	init_mutexes_locks(t_data *data, t_mutex *mutexes)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&mutexes[i++].mutex, NULL))
		{
			return (1);
		}
	}
	data->lock = malloc(sizeof(pthread_mutex_t));
	data->lock_printing = malloc(sizeof(pthread_mutex_t));
	data->lock_time = malloc(sizeof(pthread_mutex_t));
	if (!data->lock || !data->lock_printing || !data->lock_time)
	{
		return (1);
	}
	if (pthread_mutex_init(data->lock, NULL))
		return (1);
	if (pthread_mutex_init(data->lock_printing, NULL))
		return (1);
	if (pthread_mutex_init(data->lock_time, NULL))
		return (1);
	return (0);
}
