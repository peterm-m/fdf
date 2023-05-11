/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:58:16 by pedro             #+#    #+#             */
/*   Updated: 2022/04/20 21:25:07 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;

	len = (size_t)ft_strlen((char *)str) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	while (len--)
	{
		res[len] = str[len];
	}
	return (res);
}

/*
** Allocates sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it.
*/