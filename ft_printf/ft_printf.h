/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euc <euc@student.42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:53:42 by euc               #+#    #+#             */
/*   Updated: 2024/03/26 17:42:15 by euc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_put_hex(unsigned int num, const char s);
void		ft_put_ptr(unsigned long nb);
int			ft_len(int n);
int			hex_len(unsigned int num);
int			len_ptr(unsigned long nb);
int			ft_unsigned_len(unsigned int nb);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_puthex(unsigned int num, const char s);
int			ft_putptr(unsigned long ptr);
int			ft_putunsigned(unsigned int nb);
int			ft_conversion(va_list vl, const char s);
int			ft_printf(const char *s, ...);
char		*ft_char(char *s, unsigned int number, int len);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int nb);
int			ft_strlen(char *str);
int			ft_atoi(char *str);

#endif