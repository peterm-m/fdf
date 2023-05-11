/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vaprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:34:07 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/08 04:20:40 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_read_flag(const char **str_f, t_format *fmt);
static void		ft_read_width_precision(const char **str_f, t_format *fmt);
static void		ft_read_len(const char **str_f, t_format *fmt);

int	ft_vaprintf(const char *str_f, va_list va)
{
	t_format	fmt;
	int			print_len;
	int			len;

	print_len = 0;
	while (*str_f != 0)
	{
		if (*str_f != '%' && *str_f)
		{
			print_len += write(1, str_f, 1);
			str_f++;
			continue ;
		}
		str_f++;
		ft_read_flag(&str_f, &fmt);
		ft_read_width_precision(&str_f, &fmt);
		ft_read_len(&str_f, &fmt);
		len = ft_switch_conversion(&str_f, va, &fmt);
		if (len < 0)
			return (-1);
		else
			print_len += len;
	}
	return (print_len);
}

static void	ft_read_flag(const char **str_f, t_format *fmt)
{
	fmt->flags = 0;
	while (1)
	{
		if (**str_f == '0')
			fmt->flags |= F_ZERO;
		else if (**str_f == '-')
			fmt->flags |= F_LEFT;
		else if (**str_f == '+')
			fmt->flags |= F_PLUS;
		else if (**str_f == ' ')
			fmt->flags |= F_SPACE;
		else if (**str_f == '#')
			fmt->flags |= F_HASH;
		else
			break ;
		(*str_f)++;
	}
}

static void	ft_read_width_precision(const char **str_f, t_format *fmt)
{
	fmt->width = 0;
	fmt->precision = 0;
	if (**str_f >= '0' && **str_f <= '9')
	{
		while (**str_f >= '0' && **str_f <= '9')
			fmt->width = fmt->width * 10 + (unsigned int )(*(*str_f)++ - '0');
	}
	if (**str_f == '.')
	{
		fmt->flags |= F_PRECISION;
		(*str_f)++;
		if (**str_f >= '0' && **str_f <= '9')
		{
			while (**str_f >= '0' && **str_f <= '9')
				fmt->precision = fmt->precision * 10
					+ (unsigned int )(*(*str_f)++ - '0');
		}
	}
}

static void	ft_read_len(const char **str_f, t_format *fmt)
{
	fmt->length = 0;
	if (**str_f == 'l' && *(*str_f + 1) == 'l')
		fmt->length |= LEN_LL;
	else if (**str_f == 'l')
		fmt->length |= LEN_L;
	else if (**str_f == 'h' && *(*str_f + 1) == 'h')
		fmt->length |= LEN_HH;
	else if (**str_f == 'h')
		fmt->length |= LEN_H;
	else if (**str_f == 'j')
		fmt->length |= LEN_J;
	else if (**str_f == 'z')
		fmt->length |= LEN_Z;
	if (fmt->length > 0)
		(*str_f)++;
	if ((fmt->length & (LEN_LL | LEN_HH)))
		(*str_f)++;
}
