/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <jblache@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:53:08 by jblache           #+#    #+#             */
/*   Updated: 2021/11/15 14:55:04 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)first;
	str2 = (unsigned char *)second;
	i = 0;
	if (length == 0 || str1 == str2)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < length - 1)
		i++;
	return (str1[i] - str2[i]);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				sign;
	unsigned int	res;

	len = ft_length(n, &sign, &res);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (res == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	while (--len >= sign)
	{
		str[len] = res % 10 + '0';
		res /= 10;
	}
	return (str);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	n;
	int				sign;

	n = 0;
	sign = 1;
	if (nptr == NULL)
		return (-1);
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n *= 10;
		n += (*nptr - 48);
		nptr++;
	}
	return (n * sign);
}
