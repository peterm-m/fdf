/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:34:55 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/08 04:20:21 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_conversion(t_format *fmt, char a)
{
	int	len_print;

	len_print = 0;
	fmt->inbuffer = 1;
	if (!(fmt->flags & F_LEFT))
	{
		while (fmt->inbuffer++ < fmt->width)
			len_print += write(1, " ", 1);
	}
	len_print += write(1, &a, 1);
	if ((fmt->flags & F_LEFT))
	{
		while (fmt->inbuffer++ < fmt->width)
			len_print += write(1, " ", 1);
	}
	return (len_print);
}

int	ft_str_conversion(t_format *fmt, const char *str)
{
	int	len_print;

	fmt->inbuffer = 0;
	len_print = 0;
	if (str == NULL)
		return (ft_printf("(null)"));
	while (str[fmt->inbuffer] != '\0')
		fmt->inbuffer++;
	if (fmt->flags & F_PRECISION)
		if (fmt->inbuffer >= fmt->precision)
			fmt->inbuffer = fmt->precision;
	if (!(fmt->flags & F_LEFT))
		while (fmt->inbuffer++ < fmt->width)
			len_print += write(1, " ", 1);
	while (*str && (!(fmt->flags & F_PRECISION) || fmt->precision--))
		len_print += write(1, str++, 1);
	if ((fmt->flags & F_LEFT))
		while (fmt->inbuffer++ < fmt->width)
			len_print += write(1, " ", 1);
	return (len_print);
}
