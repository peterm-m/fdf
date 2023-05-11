/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:24:41 by pedro             #+#    #+#             */
/*   Updated: 2022/04/20 22:00:00 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int filedes)
{
	int	i;

	i = 0;
	if (str == NULL || filedes < 0)
		return ;
	while (str[i] != '\0')
	{
		write(filedes, &str[i], 1);
		i++;
	}
	write(filedes, "\n", 1);
}

/*
** Outputs the string s to the file descriptor fd followed by a ’\n’.
*/