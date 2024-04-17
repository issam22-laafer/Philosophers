/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:48:36 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 15:56:27 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Malloc error\n");
		return (1);
	}
	if (nb_params(ac) == 1)
		return (1);
	if (parsing(ac, av, data) == 1)
		return (1);
	if (data->n_philos == 0 || data->times_must_eat == 0)
		return (0);
	data->start = 0;
	philo(data);
}
