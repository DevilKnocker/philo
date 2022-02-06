/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <jblache@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:47:46 by jblache           #+#    #+#             */
/*   Updated: 2021/12/02 12:37:25 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_spaghetti(t_philo *philo)
{
	pthread_mutex_lock(&philo->ptr->philo[philo->nb].fork);
	philowrite(philo, " has taken a fork\n", 0, 0);
	if (philo->ptr->nb != 1)
	{
		if (philo->nb == philo->ptr->nb - 1)
			pthread_mutex_lock(&philo->ptr->philo[0].fork);
		else
			pthread_mutex_lock(&philo->ptr->philo[philo->nb + 1].fork);
		philowrite(philo, " has taken a fork\n", 0, 0);
		philo->deadtime = philo->ptr->timenb + philo->ptr->time_to_die;
		philowrite(philo, " is eating\n", philo->ptr->eat_time, 0);
		pthread_mutex_unlock(&philo->ptr->philo[philo->nb].fork);
		if (philo->nb == philo->ptr->nb - 1)
			pthread_mutex_unlock(&philo->ptr->philo[0].fork);
		else
			pthread_mutex_unlock(&philo->ptr->philo[philo->nb + 1].fork);
		if (philo->ptr->meal_need != -1)
			philo->eat_count++;
	}
}

void	*thread_start(void *philoptr)
{
	t_philo	*philo;

	philo = philoptr;
	while (philo->ptr->start == 0)
		;
	philo->deadtime = philo->ptr->timenb + philo->ptr->time_to_die;
	if (philo->nb % 2 == 1)
		usleep(3000);
	while (philo->ptr->isdead != 1 && philo->eat_count < \
	philo->ptr->meal_need)
	{
		eating_spaghetti(philo);
		if (philo->ptr->nb == 1)
			custom_usleep(philo->ptr, philo->ptr->time_to_die + 10, \
			philo->ptr->timenb);
		if (philo->ptr->nb != 1 && philo->eat_count != philo->ptr->meal_need)
		{
			philowrite(philo, " is sleeping\n", philo->ptr->sleep_time, 0);
			philowrite(philo, " is thinking\n", 0, 0);
		}
	}
	pthread_mutex_lock(&philo->ptr->life);
	philo->ptr->deadcount++;
	pthread_mutex_unlock(&philo->ptr->life);
	return (NULL);
}

int	thread_init(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb)
	{
		info->philo[i].nb = i;
		if (info->meal_need != -1)
			info->philo[i].eat_count = 0;
		else
			info->philo[i].eat_count = -2;
		info->philo[i].ptr = info;
		pthread_mutex_init(&info->philo[i].fork, NULL);
		pthread_create(&info->philo[i].thread, NULL, \
		&thread_start, &info->philo[i]);
		gettimeofday(&info->timestart, NULL);
		gettimeofday(&info->timenow, NULL);
		info->timenb = (info->timenow.tv_sec - info->timestart.tv_sec) * 1000 \
		+ (info->timenow.tv_usec - info->timestart.tv_usec) / 1000;
		info->philo[i].deadtime = info->timenb + info->time_to_die;
		i++;
	}
	info->start = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;

	if (argc < 5 || argc > 6 || init_info(argv, &info) || thread_init(&info))
		return (-1);
	while (info.deadcount < info.nb)
	{
		i = 0;
		gettimeofday(&info.timenow, NULL);
		info.timenb = (info.timenow.tv_sec - info.timestart.tv_sec) * 1000 \
		+ (info.timenow.tv_usec - info.timestart.tv_usec) / 1000;
		while (i < info.nb && !info.isdead)
		{
			if (info.philo[i].eat_count < info.meal_need && \
			info.timenb > info.philo[i].deadtime)
			{
				philowrite(&info.philo[i], " died\n", 0, 1);
				info.isdead = 1;
				pthread_mutex_unlock(&info.write);
			}
			i++;
		}
		usleep(100);
	}
	ft_free_end(info);
}
