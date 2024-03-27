/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euc <euc@student.42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:31:18 by euc               #+#    #+#             */
/*   Updated: 2024/03/27 14:14:32 by euc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	bit_sender(int pid, char *str, size_t len)
{
	int		sh;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		sh = 0;
		while (sh < 7)
		{
			if ((str[i] >> sh) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			sh++;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		bit_sender(pid, str, ft_strlen(str));
	}
	else
		ft_printf("Usage: %s <pid> <string>\n", argv[0]);
	return (0);
}
