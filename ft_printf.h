/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:12 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/19 15:47:29 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	left_justify;
	int	show_sign;
	int	blank_space;
	int	hex_prefix;
	int	zero_padding;
	int	width;
	int	precision;
}	t_flags;

int		ft_printf(const char *format, ...);
t_flags	*get_flags(const char **format);
int		format_char(char c, t_flags *flags);
int		format_str(char *s, t_flags *flags);
int		format_nbr(int64_t n, t_flags *flags);
int		format_ptr(unsigned long n, t_flags *flags);
int		format_hex(unsigned long n, int upper, t_flags *flags);

#endif
