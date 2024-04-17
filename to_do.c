/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:37:29 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 14:50:01 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_one(t_philo *philo)
{
	int	end_variable;

	if (philo->data->n_philos == 1)
	{
		pthread_mutex_lock(philo->data->lock);
		end_variable = philo->data->end;
		pthread_mutex_unlock(philo->data->lock);
		while (end_variable == 0)
		{
			pthread_mutex_lock(philo->data->lock);
			end_variable = philo->data->end;
			pthread_mutex_unlock(philo->data->lock);
		}
		pthread_mutex_unlock(philo->left);
		return (1);
	}
	return (0);
}

int	check_number_meals(t_philo *philo)
{
	int	times_eat;

	pthread_mutex_lock(philo->data->lock);
	times_eat = philo->data->times_must_eat;
	pthread_mutex_unlock(philo->data->lock);
	if (philo->number_of_meals == times_eat)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_lock(philo->data->lock_time);
		philo->data->number_philos_ate++;
		pthread_mutex_unlock(philo->data->lock_time);
		return (1);
	}
	return (0);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_taking_fork1(philo);
	if (check_one(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->right);
	print_taking_fork2(philo);
	pthread_mutex_lock(philo->data->lock_time);
	philo->last_time_eat = get_current_time();
	pthread_mutex_unlock(philo->data->lock_time);
	ft_usleep(philo->data->time_eat);
	number_of_meals_counter(philo);
	if (check_number_meals(philo) == 1)
		return (1);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	return (0);
}

int	sleep_(t_philo *philo)
{
	struct timeval	current_time;
	long			time_passed;

	gettimeofday(&current_time, NULL);
	time_passed = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000))
		- philo->data->start;
	if (print_sleep(philo, time_passed) == 1)
		return (1);
	ft_usleep(philo->data->time_sleep);
	return (0);
}

int	think(t_philo *philo)
{
	struct timeval	current_time;
	long			time_passed;

	gettimeofday(&current_time, NULL);
	time_passed = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000))
		- philo->data->start;
	if (print_think(philo, time_passed) == 1)
		return (1);
	return (0);
}
