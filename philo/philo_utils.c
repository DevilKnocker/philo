/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <jblache@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:54:20 by jblache           #+#    #+#             */
/*   Updated: 2021/12/02 12:29:15 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	custom_usleep(t_info *info, int ms, long int timestamp_start)
{
	while (info->timenb - timestamp_start < ms)
	{
		if (info->isdead == 1)
			return ;
		usleep(200);
	}
}

void	philowrite(t_philo *philo, char *str, int sleeplen, int ismain)
{
	pthread_mutex_lock(&philo->ptr->write);
	if (philo->ptr->isdead == 1)
	{
		pthread_mutex_unlock(&philo->ptr->write);
		return ;
	}
	ft_putnbr_fd(philo->ptr->timenb, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->nb + 1, 1);
	write(1, str, ft_strlen(str));
	if (!ismain)
	{
		pthread_mutex_unlock(&philo->ptr->write);
		custom_usleep(philo->ptr, sleeplen, philo->ptr->timenb);
	}
}

void	ft_free_end(t_info info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info.write);
	pthread_mutex_destroy(&info.life);
	i = 0;
	while (i < info.nb)
	{
		pthread_mutex_destroy(&info.philo[i].fork);
		pthread_join(info.philo->thread, NULL);
		i++;
	}
	free(info.philo);
}
