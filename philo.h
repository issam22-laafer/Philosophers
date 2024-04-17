/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:08:00 by lissam            #+#    #+#             */
/*   Updated: 2024/04/17 15:16:49 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

typedef struct data
{
	long			n_philos;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			times_must_eat;
	long			start;
	int				end;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*lock_printing;
	pthread_mutex_t	*lock_time;
	int				number_philos_ate;
	pthread_t		monitor;
}					t_data;

typedef struct philo
{
	pthread_t		t;
	int				id;
	int				number_of_meals;
	long			last_time_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_data			*data;
}					t_philo;

typedef struct my_mutex
{
	pthread_mutex_t	mutex;
}					t_mutex;

int					nb_params(int ac);
int					parsing(int ac, char **av, t_data *data);
void				error_number_character(void);
int					check_lenght(char *av);
int					ft_strlen(char *str);
long				ft_atol(char *str);
int					if_number(int ac, char **av);
void				philo(t_data *data);
void				error_pthread_create(void);
long				get_current_time(void);
int					ft_usleep(long milliseconds);
int					print_sleep(t_philo *philo, long time_passed);
int					print_think(t_philo *philo, long time_passed);
int					print_taking_fork1(t_philo *philo);
int					print_taking_fork2(t_philo *philo);
int					eat(t_philo *philo);
int					sleep_(t_philo *philo);
int					think(t_philo *philo);
void				number_of_meals_counter(t_philo *philo);
void				join_destroy(t_data *data, t_philo *philos,
						t_mutex *mutexes);
void				init(t_data *data, t_philo *philo, t_mutex *mutexes, int i);
#endif