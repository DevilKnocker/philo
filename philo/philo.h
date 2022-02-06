/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <jblache@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:47:40 by jblache           #+#    #+#             */
/*   Updated: 2021/11/15 15:01:07 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_info
{
	int				nb;
	int				fedcount;
	int				start;
	int				sleep_time;
	int				eat_time;
	int				time_to_die;
	int				meal_need;
	int				isdead;
	int				deadcount;
	pthread_mutex_t	write;
	pthread_mutex_t	life;
	struct s_philo	*philo;
	struct timeval	timestart;
	struct timeval	timenow;
	long int		timenb;
}					t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				eat_count;
	int				nb;
	long int		deadtime;
	t_info			*ptr;
	pthread_mutex_t	fork;
}				t_philo;

void	ft_free_end(t_info info);
int		thread_init(t_info *info);
void	*thread_start(void *philoptr);
void	eating_spaghetti(t_philo *philo);
void	philowrite(t_philo *philo, char *str, int sleeplen, int ismain);
void	custom_usleep(t_info *info, int ms, long int timestamp_start);
int		init_info(char **argv, t_info *info);
int		basic_errors(char **argv);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_strncmp(const char *first, const char *second, size_t length);
int		ft_length(int n, int *sign, unsigned int *res);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_recursive(unsigned int n, int fd);

#endif