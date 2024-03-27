/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euc <euc@student.42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:10:03 by euc               #+#    #+#             */
/*   Updated: 2024/01/02 17:22:21 by euc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char f)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, f);
		ft_put_hex(num % 16, f);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (f == 'x')
				ft_putchar((num - 10 + 'a'));
			if (f == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int num, const char f)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, f);
	return (hex_len(num));
}
