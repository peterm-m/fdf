/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:07:55 by pedromar          #+#    #+#             */
/*   Updated: 2022/04/20 21:08:51 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	t;

	srclen = 0;
	t = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (dst[0] == '\0' && src[0] == '\0')
		return (0);
	while (t + 1 < size && src[t] != '\0')
	{
		dst[t] = src[t];
		t++;
	}
	if (size > 0)
		dst[t] = '\0';
	return (srclen);
}

/*
** Takes the destination's size as a parameter and will not write more than
** that many bytes, to prevent buffer overflow (assuming size is correct).
** Writes a single NULL byte to the destination (if size is not zero).
** The resulting string is guaranteed to be NULL-terminated even if truncated.
** Returns the length of the entire source string.
*/