/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:00:53 by pedro             #+#    #+#             */
/*   Updated: 2023/05/07 21:28:22 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddf(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstaddb(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		aux = *(lst);
		while (aux->next != NULL)
			aux = aux->next;
	aux->next = new;
	}
}
