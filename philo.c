/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:08:40 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 15:16:36 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philos)
{
	t_philo	*philo;
	int		end_variable;

	philo = (t_philo *)philos;
	if (philo->id % 2 == 0)
		ft_usleep(50);
	pthread_mutex_lock(philo->left);
	end_variable = philo->data->end;
	pthread_mutex_unlock(philo->left);
	while (end_variable == 0)
	{
		if (eat(philo) == 1)
			break ;
		if (sleep_(philo) == 1)
			break ;
		if (think(philo) == 1)
			break ;
		pthread_mutex_lock(philo->left);
		end_variable = philo->data->end;
		pthread_mutex_unlock(philo->left);
	}
	return (0);
}

int	check_death(t_philo *philo)
{
	t_data	*mydata;

	mydata = philo->data;
	pthread_mutex_lock(philo->data->lock_time);
	if (((mydata->times_must_eat != -1
				&& philo->number_of_meals < mydata->times_must_eat)
			|| mydata->times_must_eat == -1) && (get_current_time()
			- philo->last_time_eat) > mydata->time_die)
	{
		pthread_mutex_lock(philo->data->lock);
		philo->data->end = 1;
		pthread_mutex_unlock(philo->data->lock);
		pthread_mutex_lock(philo->data->lock_printing);
		printf("%ld %d died \n", get_current_time() - philo->data->start,
			philo->id);
		pthread_mutex_unlock(philo->data->lock_printing);
		pthread_mutex_unlock(philo->data->lock_time);
		return (1);
	}
	pthread_mutex_unlock(philo->data->lock_time);
	return (0);
}

void	*monitoring(void *philosophers)
{
	t_philo	*philo;
	t_data	*mydata;
	int		i;

	philo = (t_philo *)philosophers;
	mydata = philo[0].data;
	while (1)
	{
		i = 0;
		while (i < mydata->n_philos)
		{
			pthread_mutex_lock(philo[i].data->lock_time);
			if (mydata->number_philos_ate == mydata->n_philos)
			{
				pthread_mutex_unlock(philo[i].data->lock_time);
				return ((void *)1);
			}
			pthread_mutex_unlock(philo[i].data->lock_time);
			if (check_death(&philo[i]) == 1)
				return ((void *)1);
			i++;
		}
	}
	return (0);
}

void	sit_at_the_table(t_data *data, t_philo *philos, t_mutex *mutexes)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
		pthread_mutex_init(&mutexes[i++].mutex, NULL);
	data->lock = malloc(sizeof(pthread_mutex_t));
	data->lock_printing = malloc(sizeof(pthread_mutex_t));
	data->lock_time = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->lock, NULL);
	pthread_mutex_init(data->lock_printing, NULL);
	pthread_mutex_init(data->lock_time, NULL);
	i = -1;
	while (++i < data->n_philos)
	{
		init(data, &philos[i], mutexes, i);
	}
	i = -1;
	data->start = get_current_time();
	while (++i < data->n_philos)
		pthread_create(&philos[i].t, NULL, routine, &philos[i]);
}

void	philo(t_data *data)
{
	t_philo	*philos;
	t_mutex	*mutexes;

	philos = malloc(sizeof(t_philo) * data->n_philos);
	mutexes = malloc(sizeof(t_data) * data->n_philos);
	if (!philos || !mutexes)
	{
		printf("Malloc error\n");
		return ;
	}
	sit_at_the_table(data, philos, mutexes);
	monitoring(philos);
	join_destroy(data, philos, mutexes);
	pthread_mutex_destroy(data->lock);
	pthread_mutex_destroy(data->lock_printing);
	pthread_mutex_destroy(data->lock_time);
	free(data->lock);
	free(data->lock_printing);
	free(data->lock_time);
	free(data);
	free(philos);
	free(mutexes);
}