/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caykut <caykut@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:13:17 by caykut            #+#    #+#             */
/*   Updated: 2023/02/02 12:13:17 by caykut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	controlsignal(int pid, char *s)
{
	int	i;

	while (*s)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*s >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
				i--;
		}
		s++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		controlsignal(pid, av[2]);
	}
	return (0);
}
