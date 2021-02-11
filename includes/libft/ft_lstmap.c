/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:45:11 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/22 14:07:49 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Marche pas aux tests parce que del est protected
** (enlever le ' || !del' ligne 25 pour test)
*/

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lsts;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		if (!(lsts = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, lsts);
		lst = lst->next;
	}
	return (new);
}
