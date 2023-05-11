/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:22:33 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/08 04:18:26 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str_f, ...)
{
	va_list	va;
	int		print_len;

	va_start(va, str_f);
	print_len = ft_vaprintf(str_f, va);
	va_end(va);
	return (print_len);
}
