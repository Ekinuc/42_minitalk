/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euc <euc@student.42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:59:14 by euc               #+#    #+#             */
/*   Updated: 2024/01/12 19:20:28 by euc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*s;
	int		len;

	len = ft_unsigned_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	while (n != 0)
	{
		s[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (s);
}

int	ft_putunsigned(unsigned int nb)
{
	int		len;
	char	*s;

	len = 0;
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		s = ft_uitoa(nb);
		len += ft_putstr(s);
		free(s);
	}
	return (len);
}
