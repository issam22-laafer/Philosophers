/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:54:30 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 09:55:47 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_sleep(t_philo *philo, long time_passed)
{
	pthread_mutex_lock(philo->data->lock_printing);
	pthread_mutex_lock(philo->data->lock);
	if (philo->data->end == 1)
	{
		pthread_mutex_unlock(philo->data->lock_printing);
		pthread_mutex_unlock(philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(philo->data->lock);
	printf("%ld  %d is sleeping\n", time_passed, philo->id);
	pthread_mutex_unlock(philo->data->lock_printing);
	return (0);
}

int	print_think(t_philo *philo, long time_passed)
{
	pthread_mutex_lock(philo->data->lock_printing);
	pthread_mutex_lock(philo->data->lock);
	if (philo->data->end == 1)
	{
		pthread_mutex_unlock(philo->data->lock_printing);
		pthread_mutex_unlock(philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(philo->data->lock);
	printf("%ld  %d is thinking\n", time_passed, philo->id);
	pthread_mutex_unlock(philo->data->lock_printing);
	return (0);
}

int	print_taking_fork1(t_philo *philo)
{
	struct timeval	current_time;
	long			time_passed;

	gettimeofday(&current_time, NULL);
	time_passed = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000))
		- philo->data->start;
	pthread_mutex_lock(philo->data->lock_printing);
	pthread_mutex_lock(philo->data->lock);
	if (philo->data->end == 1)
	{
		pthread_mutex_unlock(philo->data->lock_printing);
		pthread_mutex_unlock(philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(philo->data->lock);
	printf("%ld  %d has taken a fork\n", time_passed, philo->id);
	pthread_mutex_unlock(philo->data->lock_printing);
	return (0);
}

int	print_taking_fork2(t_philo *philo)
{
	struct timeval	current_time;
	long			time_passed;

	gettimeofday(&current_time, NULL);
	time_passed = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000))
		- philo->data->start;
	pthread_mutex_lock(philo->data->lock_printing);
	pthread_mutex_lock(philo->data->lock);
	if (philo->data->end == 1)
	{
		pthread_mutex_unlock(philo->data->lock_printing);
		pthread_mutex_unlock(philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(philo->data->lock);
	printf("%ld  %d has taken a fork\n", time_passed, philo->id);
	printf("%ld  %d is eating\n", time_passed, philo->id);
	pthread_mutex_unlock(philo->data->lock_printing);
	return (0);
}
