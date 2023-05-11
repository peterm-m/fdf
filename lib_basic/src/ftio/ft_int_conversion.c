/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:57 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/08 04:20:09 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sint_conversion(t_format *fmt, va_list va)
{
	long long int	value;

	if (fmt->length & LEN_HH)
		value = (long long int) va_arg(va, int);
	else if (fmt->length & LEN_H)
		value = (long long int) va_arg(va, int);
	else if (fmt->length & LEN_LL)
		value = (long long int) va_arg(va, long long int);
	else if (fmt->length & LEN_L)
		value = (long long int) va_arg(va, long int);
	else
		value = (long long int) va_arg(va, int);
	if (value < 0)
	{
		fmt->flags |= F_NEGATIVE;
		return (ft_lluitoa((unsigned long long int )(0 - value), fmt));
	}
	else
		return (ft_lluitoa((unsigned long long int ) value, fmt));
}

int	ft_uint_conversion(t_format *fmt, va_list va)
{
	unsigned long long int	value;

	if (fmt->length & LEN_HH)
		value = (unsigned long long int) va_arg(va, unsigned int);
	else if (fmt->length & LEN_H)
		value = (unsigned long long int) va_arg(va, unsigned int);
	else if (fmt->length & LEN_LL)
		value = (unsigned long long int) va_arg(va, unsigned long long int);
	else if (fmt->length & LEN_L)
		value = (unsigned long long int) va_arg(va, unsigned long int);
	else
		value = (unsigned long long int) va_arg(va, unsigned int);
	return (ft_lluitoa(value, fmt));
}
