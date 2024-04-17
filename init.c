/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:19 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 15:19:08 by lissam           ###   ########.fr       */
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
