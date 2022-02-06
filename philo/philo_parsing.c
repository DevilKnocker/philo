/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <jblache@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:53:52 by jblache           #+#    #+#             */
/*   Updated: 2021/12/02 12:55:07 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	basic_errors(char **argv)
{
	int		i;
	char	*buff;

	i = 1;
	while (argv[i])
	{
		buff = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(buff, argv[i], ft_strlen(buff)) || ft_atoi(argv[i]) < 0)
		{
			free(buff);
			return (-1);
		}
		free(buff);
		i++;
	}
	return (0);
}

int	init_info(char **argv, t_info *info)
{
	if (basic_errors(argv))
		return (-1);
	info->isdead = 0;
	info->start = 0;
	info->deadcount = 0;
	info->nb = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		info->meal_need = ft_atoi(argv[5]);
	else
		info->meal_need = -1;
	info->philo = malloc(sizeof(t_philo) * info->nb);
	if (!info->philo)
		return (-1);
	pthread_mutex_init(&info->write, NULL);
	pthread_mutex_init(&info->life, NULL);
	return (0);
}
