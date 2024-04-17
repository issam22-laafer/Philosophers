/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:08:19 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 15:50:12 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_number_character(void)
{
	printf(RED " Invalide Argument \n");
}

void	error_pthread_create(void)
{
	printf(RED " Error while creating a thread \n");
}

void	error_pthread_join(void)
{
	printf(RED " Error while joining a thread \n");
}
