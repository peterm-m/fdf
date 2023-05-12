/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:29:35 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/12 18:31:34 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t ft_wc_lines(char *path)
// {
// 	path = (void *) path;
// 	printf("NOT IMPLEMENTED!!!!!!!\n");
// 	retunr (0);
// }
// 
// size_t ft_wc_words(char *path)
// {
// 	path = (void *) path;
// 	printf("NOT IMPLEMENTED!!!!!!!\n");
// 	retunr (0);
// }

size_t	ft_wc_bytes(char *path)
{
	size_t	len;
	size_t	aux;
	int		fd;
	char	buf[BUFSIZ];

	fd = open(path, O_RDONLY);
	len = read(fd, buf, BUFSIZ);
	while (1)
	{
		aux = read(fd, buf, BUFSIZ);
		if (aux > 0)
			len += aux;
		else
		{
			close(fd);
			return (len);
		}
	}
}
