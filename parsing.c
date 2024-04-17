/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:08:33 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 21:51:11 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	skip(char **av, int *i, int *j)
{
	while ((av[*i][*j] >= 9 && av[*i][*j] <= 13) || (av[*i][*j] == ' '))
		*j = *j + 1;
	if (av[*i][*j] == '+')
		*j = *j + 1;
	if (av[*i][*j] == '\0')
	{
		error_number_character();
		return (1);
	}
	return (0);
}

int	if_number(int ac, char **av)
{
	int (i), (j);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (skip(av, &i, &j) == 1)
			return (1);
		while (av[i][j] == '0')
			j++;
		if (check_lenght(av[i] + j) == 1)
			return (1);
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				error_number_character();
				return (1);
			}
			j++;
		}
	}
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	r;

	i = 0;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return (r);
}

int	parsing(int ac, char **av, t_data *data)
{
	if (if_number(ac, av) == 1)
		return (1);
	data->number_philos_ate = 0;
	data->n_philos = ft_atol(av[1]);
	data->time_die = ft_atol(av[2]);
	data->time_eat = ft_atol(av[3]);
	data->time_sleep = ft_atol(av[4]);
	if (data->n_philos > INT_MAX || data->time_die > INT_MAX
		|| data->time_eat > INT_MAX || data->time_sleep > INT_MAX)
	{
		printf(RED "Invalide Argument \n");
		return (1);
	}
	data->end = 0;
	if (ac == 6)
		data->times_must_eat = ft_atol(av[5]);
	else
		data->times_must_eat = -1;
	return (0);
}
