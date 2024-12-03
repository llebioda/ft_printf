/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:31:39 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/26 15:31:41 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_int_flag(const char **format, int error_value);
static int	find_flags(t_flags *flags, char c);
static void	ft_bzero(void *s, size_t n);

t_flags	*get_flags(const char **format)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	ft_bzero(flags, sizeof(t_flags));
	while (find_flags(flags, **format))
		(*format)++;
	flags->width = get_int_flag(format, -1);
	flags->precision = -1;
	if (**format == '.')
	{
		(*format)++;
		flags->precision = get_int_flag(format, 0);
	}
	return (flags);
}

static int	find_flags(t_flags *flags, char c)
{
	if (c == '-')
		flags->left_justify = 1;
	else if (c == '+')
		flags->show_sign = 1;
	else if (c == ' ')
		flags->blank_space = 1;
	else if (c == '#')
		flags->hex_prefix = 1;
	else if (c == '0')
		flags->zero_padding = 1;
	else
		return (0);
	return (1);
}

static int	get_int_flag(const char **format, int error_value)
{
	int	a;

	if (!(**format >= '0' && **format <= '9'))
		return (error_value);
	a = 0;
	while (**format >= '0' && **format <= '9')
	{
		a = a * 10 + (**format - '0');
		(*format)++;
	}
	return (a);
}

static void	ft_bzero(void *s, size_t n)
{
	char	*c;

	if (!s)
		return ;
	c = s;
	while (n > 0)
	{
		*c = 0;
		c++;
		n--;
	}
}
