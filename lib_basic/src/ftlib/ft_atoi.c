/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:29:39 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/17 19:10:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	sing;

	printf("%s\n", str);
	c = 0;
	sing = 1;
	while (*str == ' ' || (*str < 14 && *str > 8))
		str++;
	if (*str == '-' || *str == '+')
	{
		sing = 44 - *str;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		c = (c * 10) + (*str - '0');
		str++;
	}
	return (((int ) c) * sing);
}

/*
** Converts the initial portion of a string pointed to the variable string, to
** an int representarion (type).
*/
