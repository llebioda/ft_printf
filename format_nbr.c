/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:03:23 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/26 11:24:01 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	init_format_nbr(int64_t *n, char *p, int *nbr_len, t_flags *flags);
static int	add_precision(int nbr_len, t_flags *flags, int can_write);
static int	ft_putnbr(int64_t n, int can_write);
static int	should_put_zero(int nbr_len, t_flags *flags);

int	format_nbr(int64_t n, t_flags *flags)
{
	char	prefix;
	int		nbr_len;
	int		count;

	count = init_format_nbr(&n, &prefix, &nbr_len, flags);
	if ((prefix == '+' || prefix == '-') && should_put_zero(nbr_len, flags))
		write(1, &prefix, 1);
	while (count < flags->width && flags->left_justify == 0)
	{
		if (should_put_zero(nbr_len, flags) == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		count++;
	}
	if (prefix && !((prefix == '+' || prefix == '-')
			&& should_put_zero(nbr_len, flags)))
		write(1, &prefix, 1);
	add_precision(nbr_len, flags, 1);
	if (flags->precision != 0 || n != 0)
		ft_putnbr(n, 1);
	while (count < flags->width && flags->left_justify == 1)
		count += write(1, " ", 1);
	return (count);
}

static int	init_format_nbr(int64_t *n, char *p, int *nbr_len, t_flags *flags)
{
	int	count;

	*p = '\0';
	count = 1;
	if (*n < 0)
	{
		*p = '-';
		*n = -(*n);
	}
	else if (flags->show_sign == 1)
		*p = '+';
	else if (flags->blank_space == 1)
		*p = ' ';
	else
		count = 0;
	*nbr_len = 0;
	if (flags->precision != 0 || *n != 0)
		*nbr_len = ft_putnbr(*n, 0);
	count += add_precision(*nbr_len, flags, 0);
	return (count);
}

static int	add_precision(int nbr_len, t_flags *flags, int can_write)
{
	if (flags->precision <= 0)
		return (nbr_len);
	while (nbr_len < flags->precision)
	{
		if (can_write == 1)
			write(1, "0", 1);
		nbr_len++;
	}
	return (nbr_len);
}

static int	ft_putnbr(int64_t n, int can_write)
{
	char	c;
	int		count;

	count = 1;
	if (n >= 10)
		count += ft_putnbr(n / 10, can_write);
	if (can_write == 1)
	{
		c = '0' + n % 10;
		write(1, &c, 1);
	}
	return (count);
}

static int	should_put_zero(int nbr_len, t_flags *flags)
{
	if (flags->zero_padding == 1
		&& (flags->precision < 0 || flags->precision > nbr_len)
		&& (flags->width < flags->precision || flags->precision < nbr_len)
		&& (flags->precision != 0 || nbr_len != 0))
		return (1);
	return (0);
}
