/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:08:11 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 09:55:35 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	nb_params(int ac)
{
	if (ac == 5 || ac == 6)
	{
		return (0);
	}
	else
	{
		printf(RED "Number of params is not correct !!!\n");
		return (1);
	}
}

int	check_lenght(char *av)
{
	if (ft_strlen(av) > 10)
	{
		printf(RED " Invalide Argument \n");
		return (1);
	}
	return (0);
}
