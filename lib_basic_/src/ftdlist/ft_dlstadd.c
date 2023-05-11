/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:02:27 by pedro             #+#    #+#             */
/*   Updated: 2023/05/08 18:19:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_dlstaddb(t_dlist **lst, t_dlist *new)
{
    t_dlist *tmp;

    tmp = *lst;
    if (!tmp)
    {
        *lst = new;
        return ;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}

void    ft_dlstaddf(t_dlist **lst, t_dlist *new)
{
    if (!(*lst))
    {
        *lst = new;
        return ;
    }
    new->next = *lst;
    (*lst)->prev = new;
    *lst = new;
}

//void    ft_dlstaddia(t_dlist *lst, t_dlist *new)
//{
//}
//
//void    ft_dlstaddib(t_dlist *lst, t_dlist *new)
//{       
//}