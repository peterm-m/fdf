/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:17:10 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/13 12:18:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getfile(char *path)
{
	size_t	len_file;
	char	*file;
	int		fd;

	len_file = ft_wc_bytes(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = (char *)malloc(len_file + 1);
	if (file)
	{
		file[len_file] = '\0';
		read(fd, file, len_file);
		close(fd);
	}
	return (file);
}
