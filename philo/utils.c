/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblache <jblache@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:52:09 by jblache           #+#    #+#             */
/*   Updated: 2021/11/15 14:55:02 by jblache          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_recursive(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
		ft_recursive(n / 10, fd);
	c = 48 + n % 10;
	write(fd, &c, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	ft_recursive(nb, fd);
	return ;
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (str[i])
		str[i] = 0;
	return (memset(str, 0, count * size));
}

int	ft_length(int n, int *sign, unsigned int *res)
{
	int				len;
	unsigned int	tmp;

	*sign = 0;
	len = 0;
	*res = (unsigned int)n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		*res = (unsigned int) - n;
		*sign = 1;
	}
	tmp = *res;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	return (len += *sign);
}
