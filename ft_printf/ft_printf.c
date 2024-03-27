/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euc <euc@student.42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:53:34 by euc               #+#    #+#             */
/*   Updated: 2024/01/12 17:29:09 by euc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_conversion(va_list vl, const char s)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_putchar(va_arg(vl, int));
	else if (s == 's')
		len += ft_putstr(va_arg(vl, char *));
	else if (s == 'p')
		len += ft_putptr(va_arg(vl, unsigned long));
	else if (s == 'd' || s == 'i')
		len += ft_putnbr(va_arg(vl, int));
	else if (s == 'u')
		len += ft_putunsigned(va_arg(vl, unsigned int));
	else if (s == 'x' || s == 'X')
		len += ft_puthex(va_arg(vl, unsigned int), s);
	else if (s == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_conversion(arg, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
