/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:57 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/08 04:20:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fmt_noleft(char *buff, t_format *fmt);
static int	ft_fmt_buff(char *buff, t_format *fmt);
static void	ft_fmt_buff_hash(char *buff, t_format *fmt);
static int	ft_print_buffnum(char *buff, t_format *fmt);

int	ft_lluitoa(unsigned long long int num, t_format *fmt)
{
	char	buff[BUFFER_ULL];
	char	digit;

	if (num == 0)
		fmt->flags &= ~F_HASH;
	if (!(fmt->flags & F_PRECISION) || num)
	{
		if (num == 0 && fmt->inbuffer == 0)
				buff[fmt->inbuffer++] = '0';
		while (num && fmt->inbuffer < BUFFER_ULL)
		{
			digit = (char )(num % fmt->base);
			if (digit < 10)
				buff[fmt->inbuffer++] = '0' + digit;
			else
			{
				if (fmt->flags & F_UPPER)
					buff[fmt->inbuffer++] = 'A' + digit - 10;
				else
					buff[fmt->inbuffer++] = 'a' + digit - 10;
			}
			num /= fmt->base;
		}
	}
	return (ft_fmt_buff(buff, fmt));
}

static int	ft_fmt_buff(char *buff, t_format *fmt)
{
	if (!(fmt->flags & F_LEFT))
		ft_fmt_noleft(buff, fmt);
	if (fmt->flags & F_HASH)
		ft_fmt_buff_hash(buff, fmt);
	if (fmt->inbuffer < BUFFER_ULL)
	{
		if (fmt->flags & F_NEGATIVE)
			buff[fmt->inbuffer++] = '-';
		else if (fmt->flags & F_PLUS)
			buff[fmt->inbuffer++] = '+';
		else if (fmt->flags & F_SPACE)
			buff[fmt->inbuffer++] = ' ';
	}
	return (ft_print_buffnum(buff, fmt));
}

static void	ft_fmt_noleft(char *buff, t_format *fmt)
{
	if (fmt->width && (fmt->flags & F_ZERO)
		&& ((fmt->flags & F_NEGATIVE) || (fmt->flags & (F_PLUS | F_SPACE))))
			fmt->width--;
	while ((fmt->inbuffer < fmt->precision) && (fmt->inbuffer < BUFFER_ULL))
		buff[fmt->inbuffer++] = '0';
	while ((fmt->flags & F_ZERO) && (fmt->inbuffer < fmt->width)
		&& (fmt->inbuffer < BUFFER_ULL))
		buff[fmt->inbuffer++] = '0';
}

static void	ft_fmt_buff_hash(char *buff, t_format *fmt)
{
	if (!(fmt->flags & F_PRECISION) && fmt->inbuffer
		&& (fmt->inbuffer == fmt->precision || fmt->inbuffer == fmt->width))
	{
		fmt->inbuffer--;
		if (fmt->inbuffer && fmt->base == 16)
			fmt->inbuffer--;
	}
	if (fmt->base == 16 && !(fmt->flags & F_UPPER)
		&& (fmt->inbuffer < BUFFER_ULL))
		buff[fmt->inbuffer++] = 'x';
	else if (fmt->base == 16 && (fmt->flags & F_UPPER)
		&& (fmt->inbuffer < BUFFER_ULL))
	buff[fmt->inbuffer++] = 'X';
	else if (fmt->base == 2 && (fmt->inbuffer < BUFFER_ULL))
		buff[fmt->inbuffer++] = 'b';
	if (fmt->inbuffer < BUFFER_ULL)
		buff[fmt->inbuffer++] = '0';
}

static int	ft_print_buffnum(char *buff, t_format *fmt)
{
	unsigned int	len_print;
	unsigned int	aux;

	len_print = 0;
	aux = fmt->inbuffer;
	if (!(fmt->flags & F_LEFT) && !(fmt->flags & F_ZERO))
	{
		while (aux++ < fmt->width)
			len_print += write(1, " ", 1);
	}
	while (fmt->inbuffer)
		len_print += write(1, &buff[--fmt->inbuffer], 1);
	if (fmt->flags & F_LEFT)
	{
		while (len_print < fmt->width)
			len_print += write(1, " ", 1);
	}
	return (len_print);
}
