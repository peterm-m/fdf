/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:40:55 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/07 21:38:40 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void *data)
{
    t_dlist *new;

    new = (t_dlist *)malloc(sizeof(t_dlist));
    if (new)
    {
        new->data = data;
        new->next = NULL;
        new->prev = NULL;
    }
    return(new);
}