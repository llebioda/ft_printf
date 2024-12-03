/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:39:24 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/18 10:40:27 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_null_str(t_flags *flags);

int	format_char(char c, t_flags *flags)
{
	int		count;

	count = 1;
	while (count < flags->width && flags->left_justify == 0)
		count += write(1, " ", 1);
	write(1, &c, 1);
	while (count < flags->width && flags->left_justify == 1)
		count += write(1, " ", 1);
	return (count);
}

int	format_str(char *s, t_flags *flags)
{
	int	count;
	int	len;

	if (s == NULL)
		return (format_null_str(flags));
	len = 0;
	while (s[len])
		len++;
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	count = len;
	while (count < flags->width && flags->left_justify == 0)
		count += write(1, " ", 1);
	write(1, s, len);
	while (count < flags->width && flags->left_justify == 1)
		count += write(1, " ", 1);
	return (count);
}

static int	format_null_str(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision < 0 || flags->precision >= 6)
		count = 6;
	while (count < flags->width && flags->left_justify == 0)
		count += write(1, " ", 1);
	if (flags->precision < 0 || flags->precision >= 6)
		write(1, "(null)", 6);
	while (count < flags->width && flags->left_justify == 1)
		count += write(1, " ", 1);
	return (count);
}
