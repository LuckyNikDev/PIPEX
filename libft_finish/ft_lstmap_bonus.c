/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:45:34 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/22 10:51:50 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mylst;
	t_list	*buflist;

	buflist = NULL;
	while (lst)
	{
		mylst = ft_lstnew(f(lst->content));
		if (mylst)
			ft_lstadd_back(&buflist, mylst);
		else
		{
			ft_lstclear(&buflist, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (buflist);
}
