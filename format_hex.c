/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <lowanlebioda@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:03:23 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/26 11:17:31 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	init_hex(unsigned long n, int *pre, int *hex_len, t_flags *flags);
static int	ft_puthex(unsigned long n, int up, int can_write);

int	format_ptr(unsigned long n, t_flags *flags)
{
	int	count;

	if (n == 0)
	{
		count = 5;
		while (count < flags->width && flags->left_justify == 0)
			count += write(1, " ", 1);
		write(1, "(nil)", 5);
		while (count < flags->width && flags->left_justify == 1)
			count += write(1, " ", 1);
		return (count);
	}
	flags->hex_prefix = 1;
	return (format_hex(n, 0, flags));
}

int	format_hex(unsigned long n, int upper, t_flags *flags)
{
	int	count;
	int	precision;
	int	hex_len;

	count = init_hex(n, &precision, &hex_len, flags);
	while (count < flags->width && flags->left_justify == 0)
		count += write(1, " ", 1);
	if (flags->hex_prefix == 1)
	{
		if (upper == 1)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	while (precision > hex_len++)
		write(1, "0", 1);
	if (precision != 0 || n != 0)
		ft_puthex(n, upper, 1);
	while (count < flags->width && flags->left_justify == 1)
		count += write(1, " ", 1);
	return (count);
}

static int	init_hex(unsigned long n, int *pre, int *hex_len, t_flags *flags)
{
	int	count;

	count = 0;
	if (n == 0)
		flags->hex_prefix = 0;
	if (flags->hex_prefix == 1)
		count = 2;
	*pre = flags->precision;
	if (flags->width - count > *pre && *pre < 0 && flags->zero_padding)
		*pre = flags->width - count;
	*hex_len = 0;
	if (*pre != 0 || n != 0)
		*hex_len = ft_puthex(n, 0, 0);
	if (*pre > *hex_len)
		count += *pre - *hex_len;
	count += *hex_len;
	return (count);
}

static int	ft_puthex(unsigned long n, int up, int can_write)
{
	const char	g_hex_base[32] = "0123456789abcdef0123456789ABCDEF";
	int			count;

	count = 1;
	if (up != 1)
		up = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, up, can_write);
	if (can_write == 1)
		write(1, g_hex_base + (n % 16 + up * 16), 1);
	return (count);
}
