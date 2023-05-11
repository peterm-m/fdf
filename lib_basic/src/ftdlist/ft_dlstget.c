/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:25:04 by pedro             #+#    #+#             */
/*   Updated: 2023/05/07 23:59:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstgetb(t_dlist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_dlist	*ft_dlstgeth(t_dlist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->prev != NULL)
	{
		lst = lst->prev;
	}
	return (lst);
}