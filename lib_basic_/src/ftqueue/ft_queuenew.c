/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:37:03 by pedro             #+#    #+#             */
/*   Updated: 2023/05/07 21:46:27 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue *ft_queuenew(void *data)
{
    t_queue *new;

    new = (t_queue *)malloc(sizeof(t_queue));
    if (new)
    {
        new->head = NULL;
        new->tail = NULL;
    }
    return (new);
}
