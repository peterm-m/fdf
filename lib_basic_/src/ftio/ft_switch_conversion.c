/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:09:52 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/08 04:21:44 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_fmt(const char *str_f, t_format *fmt, va_list va);
static int	ft_char_fmt(const char *str_f, t_format *fmt, va_list va);
static int	ft_other_fmt(const char *str_f, t_format *fmt, va_list va);
static int	ft_double_fmt(void );

int	ft_switch_conversion(const char **str_f, va_list va, t_format *fmt)
{
	int	len;

	fmt->inbuffer = 0;
	if (**str_f == 'i' || **str_f == 'd'
		|| **str_f == 'o' || **str_f == 'u'
		|| **str_f == 'b' || **str_f == 'x'
		|| **str_f == 'X')
		len = ft_int_fmt(*str_f, fmt, va);
	else if (**str_f == 'f' || **str_f == 'a'
		|| **str_f == 'e' || **str_f == 'g')
		len = ft_double_fmt();
	else if (**str_f == 'c' || **str_f == 's')
		len = ft_char_fmt(*str_f, fmt, va);
	else if (**str_f == '%' || **str_f == 'p')
		len = ft_other_fmt(*str_f, fmt, va);
	else
		return (-1);
	(*str_f)++;
	return (len);
}

static int	ft_int_fmt(const char *str_f, t_format *fmt, va_list va)
{
	if (*str_f == 'x' || *str_f == 'X')
		fmt->base = 16;
	else if (*str_f == 'o')
		fmt->base = 8;
	else if (*str_f == 'b')
		fmt->base = 2;
	else
	{
		fmt->base = 10;
		fmt->flags &= ~F_HASH;
	}
	if (*str_f == 'X')
		fmt->flags |= F_UPPER;
	if (*str_f != 'i' && *str_f != 'd')
		fmt->flags &= ~(F_PLUS | F_SPACE);
	if (fmt->flags & F_PRECISION)
		fmt->flags &= ~F_ZERO;
	if (*str_f == 'i' || *str_f == 'd')
		return (ft_sint_conversion(fmt, va));
	else
		return (ft_uint_conversion(fmt, va));
}

static int	ft_char_fmt(const char *str_f, t_format *fmt, va_list va)
{
	if (*str_f == 'c')
		return (ft_char_conversion(fmt, (char )va_arg(va, int)));
	else
		return (ft_str_conversion(fmt, (const char *) va_arg(va, char *)));
}

static int	ft_double_fmt(void )
{
	return (ft_double_conversion());
}

static int	ft_other_fmt(const char *str_f, t_format *fmt, va_list va)
{
	int						len_print;
	unsigned long long int	arg;

	len_print = 0;
	if (*str_f == '%')
		len_print += write(1, "%", 1);
	else
	{
		arg = (unsigned long long int ) va_arg(va, void *);
		if (arg == 0)
			len_print += ft_printf("0x0");
		else
		{
			fmt->flags |= F_HASH;
			fmt->base = 16;
			len_print += ft_lluitoa(arg, fmt);
		}
	}
	return (len_print);
}
