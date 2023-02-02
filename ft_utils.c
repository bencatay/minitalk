/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caykut <caykut@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:02:22 by caykut            #+#    #+#             */
/*   Updated: 2023/02/02 12:02:24 by caykut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)

{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)

{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	if (n < 10)
	{
		ft_putchar_fd((n + '0'), fd);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	res;

	i = 0;
	a = 0;
	res = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			res *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (str[i] - '0') + (a * 10);
		i++;
	}
	return (res * a);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
