/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:03:23 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/18 16:36:21 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(va_list ap, const char **format);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		r_val;
	int		count;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			r_val = handle_format(ap, &format);
			if (r_val == -1 || count == -1)
				count = -1;
			else
				count += r_val;
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

int	handle_format(va_list ap, const char **format)
{
	t_flags	*flags;
	int		count;

	flags = get_flags(format);
	if (**format == 'c')
		count = format_char((char)va_arg(ap, int), flags);
	else if (**format == 's')
		count = format_str(va_arg(ap, char *), flags);
	else if (**format == 'p')
		count = format_ptr((unsigned long)va_arg(ap, void *), flags);
	else if (**format == 'd' || **format == 'i')
		count = format_nbr((int64_t)va_arg(ap, int), flags);
	else if (**format == 'u')
		count = format_nbr((int64_t)va_arg(ap, unsigned int), flags);
	else if (**format == 'x' || **format == 'X')
		count = format_hex(va_arg(ap, unsigned int), **format == 'X', flags);
	else
		count = write(1, "%", 1);
	free(flags);
	return (count);
}
